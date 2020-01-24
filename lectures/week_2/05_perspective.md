# Perspective Viewing

## Orthographic Projection
The approach that we have followed up until this point has been to shoot rays
that all have the same direction but different origins, mainly the centre (or
sample point) within each pixel. These rays are ultimately computing the
*projection* of our objects in 3D space onto a flat 2D surface called the
*viewing plane*. 

If we draw lines that pass through the corners of the viewing plane and are
parallel to the direction of the rays, we would end up with an infinite box,
which is called the *viewing volume*. Anything within the volume will be
projected onto our viewing plane, while everything outside will not be visible.
In ray tracing, we do not have to do any special culling of objects that sit
outside of our viewing volume, as the rays will never hit them and so they
become irrelevant. We can also define a *near* and *far* plane to determine how
far back we allow objects to be in our scene. While this process is important
for real-time systems, ray tracing does not require them to be there. This
current system is called *orthographic projection* and is commonly used in
modelling software and CAD systems.

## Perspective Projection

The idea we will now explore is to reverse the conditions of the rays: before
they all had the same direction, but different origins. We will now have rays
that have the same *origin* but different *direction*. Specifically, we are
going to define a *centre of projection* which will be the origin for all the
rays. The direction will then be determined in relation to the centre of each
pixel (or sample point). This new system is called *perspective projection*.

Given that we have now changed the rays, we will now discuss the consequences
that this change has. First, the viewing volume is no longer an infinite box.
Instead, the viewing volume is now an infinite pyramid, whose peak is the centre
of projection. This is called the *viewing frustum*. Similar to before, we can
define the near and far planes, though they are not strictly speaking necessary
in ray tracing. Another quantity that appears is called the *field of view*,
which is defined as the angle subtended at the centre of projection by the top
and bottom edges of the window (or viewing plane). The ratio between the width
and height of the viewing plane is called the *aspect ratio*.

## Properties of Perspective Projection

We will now discuss the properties that the projection has and the effects that
it will have on the projected objects.

1. *The perspective projection of an object becomes smaller as the object gets
   further away from the centre of projection.* This is the main reason why
   perspective projections are more realistic. If we think about what happens to
   objects that are further away, they do indeed seem smaller and they get
   larger as they move closer to us.
2. *As an object is rotated, its projected width becomes smaller. This is known
   as foreshortening.* This comes as a consequence of the first property.
   Imagine a thin rectangular box that is parallel to us. As we rotate the box,
   one side will move further away from the centre of projection and will
   therefore appear smaller. Conversely, the side of the box that is moving
   towards us will be closer and will therefore appear larger.
3. *Perspective projections preserve straight lines.* This is fairly apparent,
   and is something that is not required by all types of projections. In fact, a
   type of projection called the *fish-eye* projection (which is used by GoPro
   cameras for example) does not maintain straight lines.
4. *Sets of parallel lines that are parallel to the view plane remain parallel
   when projected onto the view plane.* We can see this also as a consequence of
   properties 1 and 3. A line that is parallel to the view plane will maintain
   the same distance and will always be the same size. If we add a second line
   to the mix, we will have two parallel lines.
5. *Sets of parallel lines that are not parallel to the view plane converge to a
   vanishing point on the view plane.* This also comes as a consequence of
   properties 1 and 3. Specifically, if the lines aren't parallel with the view
   plane, there will be points on the lines that will be further away and will
   be smaller. Since the line must remain straight, any pair of lines not
   parallel to the view plane will therefore seem to converge at a point, which
   is known as the *vanishing point*.

## Vanishing Points

Before we discuss further about vanishing points, we will define the *ground
plane*. Consider a plane that is parallel to the z-axis and therefore
perpendicular to our viewing plane. Any ray that is shot from the upper half of
the viewing plane will not intersect it, while rays shot from the lower half
will. Any ray shot from the centre will "hit" at some point in infinity. These
rays are the ones that contribute to the formation of the *horizon*. In this
configuration, the horizon will be a horizontal line across the centre of the
viewing plane.

The reason to discuss the horizon is that the *vanishing points of horizontal
lines are always on the horizon*. This is due to the fact that the vanishing
points are at an infinite distance away from us, which coincidentally is the
same location of the horizon itself.

We can classify perspective views by the number of vanishing points. Consider
two cubes. If we set them side by side, then the lines of the cubes that are not
parallel to the viewing plane will converge at the same vanishing point. This
system is therefore known as a *one-point* perspective view. Now take the cubes
and rotate them so they have no edges aligned with the viewing plane. The edges
will now converge on two points, which results in a *two-point* perspective
view. Finally, if we align a corner of the cube with the viewing plane, we will
end up with a *three-point* perspective view. This leads to the final property:

6. *If a set of parallel lines is parallel to the world coordinate axis, its
   vanishing point is on the axis and is known as the principal vanishing
   point*.

In fact, the number of principal vanishing points is related to the number of of
world coordinate planes (or axes) that the view plane cuts.

## Axis-Aligned Perspective Viewing

The simplest way to implement perspective viewing is to simply move the origins
of the rays to a single point, which we will call the *eye*. For the sake of
simplicity, we will place the eye on the z-axis, which results in an
*axis-aligned perspective*. The new directions of the rays are therefore
computed as the point on the pixel minus the eye. The resulting vector must then
be normalized and can be used in our calculations.

## Processes and Results

Now that we have our viewing system setup, we can now begin to explore what
happens when certain quantities are changed. First, we will define $d$ as the
distance between the eye and the viewing plane. Let's see what happens when we
change it:

* If $d$ decreases, then the eye moves closer to the viewing plane. This results
  in the field of view *increasing*. The effect that this will have on the
  projected objects is that they will appear *smaller*. The reasoning behind
  this is the following: suppose that an object occupies a certain percentage of
  the field of view. If I move $d$ such that the field of view is doubled, then
  the percentage that the object occupies will be halved. Notice that the size
  of the object is constant, and what is changing is the *perceived* or
  *projected* size of the object.
* If $d$ increases, then the eye moves further away from the viewing plane,
  causing the field of view to *decrease*. This will result in the size of
  projected objects to *increase*.

These two properties of $d$ can be used together to emulate a zooming system.

Now let us consider what happens when the *entire* unit is moved together. That
is to say, let us hold $d$ constant, and lets move the eye, and the viewing
plane together. Since $d$ is constant, the field of view remains the same. As we
move closer to the objects, they will appear larger, but something else will
happen as well: objects that are further away will start to appear smaller,
while objects (or parts of objects) that are closer will be bigger. This is
known as *perspective distortion* and is a direct consequence of the properties
we discussed earlier. This type of movement is therefore *not* the same as
zooming in.

Now do all objects experience distortion? The answer is yes. Do all of them
experience it in the same way? No. Objects that have straight lines in them
will retain their overall shape. Their dimensions might change, but their shapes
will remain. Objects that are curved on the other hand will be distorted more
severely by this, to the point where spheres will become ellipsoids.
