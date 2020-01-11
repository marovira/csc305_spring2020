# Math Primer

## Quick Recap: Sets and Intervals

* Set is an *unordered* collection of objects of the same type. The objects
  conforming the set are called *elements*. While the elements can be of any
  type, in graphics we usually deal with floating-point (real) numbers. Some
  examples of these are: $\mathbb{R}$, $\mathbb{R}^+$, $\mathbb{R}^2$, and
  $\mathbb{R}^3$. The empty set is denoted as $\emptyset$.
* If $x$ belongs in a set $S$, we use the notation $s \in S$. Sets can also be
  defined using the *predicate form* which explains which elements compose the
  set. For example: $\mathbb{R}^+ = \lbrace x : x \in \mathbb{R}, x \geq 0
  \rbrace$.
* We can also say that $B$ is a subset of $A$ if all the elements of $B$ are
  themselves elements of $A$ and is denoted as $B \subseteq A$.
* An *ordered pair* of elements is a sequence of two elements in a definitive
  order. An example is $(x, y)$ which defines a point in the $xy$-plane. The set
  of all ordered pairs is called the *cartesian product* and is represented as
  $A \times B$. Therefore, $\mathbb{R}^2 = \mathbb{R} \times \mathbb{R}$.
* An *interval* is a subset of the real line that contains at least two numbers,
  and contains all the real numbers lying between any two of its elements. There
  are several kinds, but they are all defined by a combination of $()$ or $[]$.
  So if we have a set that begins with $(a$, then the set does not contain $a$.
  Likewise, if it ends with $b)$, then the set does not contain $b$. Conversely,
  if it starts with $[a$ or ends with $b]$, then the set contains $a$ or $b$,
  respectively.
* Intervals behave exactly like sets, and therefore we can take the
  intersection, union, and cartesian products of intervals.

## Quick Recap: Angles and Trigonometry.

* Positive Angles are measured *counterclockwise* from the positive $x$-axis,
  while negative angles are measured in a *clockwise* direction.
* We generally handle angles in radians whenever we are dealing with *any*
  trigonometric function, though we may discuss them in degrees for the sake of
  simplicity. Recall that to convert from degrees to radians we use $r = (180 /
  \pi)d$. 
* The two fundamental trigonometric functions we will be using are
  $\sin(\theta)$ and $\cos(\theta)$. OF these two, the important relations are:
    * $\sin^2\theta + \cos^2\theta = 1$
    * $\sin(\theta \pm \phi) = \sin\theta\cos\phi \pm \cos\theta\sin\phi$
    * $\cos(\theta \pm \phi) = \cos\theta\cos\phi \mp \sin\theta\sin\phi$

## Quick Recap: Coordinate Systems

* Graphics utilizes the following coordinate systems:
    * Model/World coordinates: 3D
    * View coordinates: 3D
    * View-plane: 2D
    * Texture coordinates: 2D and 3D
* We will discuss what these mean later, but for now it is important to note
  that in graphics, the $z$ and $y$ axis trade places, with positive $y$ going
  up and positive $z$ pointing out from the page. There is no fundamental
  difference between this and what is taught in math, it is merely a choice of
  representation.
* Cylindrical coordinates are defined by the triplet $r, \phi, y$, where $r$ is
  the radius of the cylinder, $\phi$ is the angle about the $y$ axis, and $y$
  represents the height on the cylinder. To convert between cartesian and
  cylindrical coordinates we use:
    * $x = r\sin\phi$
    * $y = y$
    * $z = r\cos\phi$
* Spherical coordinates are defined by the triplet $r, \theta, \phi$, where $r$
  is the radius of the sphere, $\theta$ is called the polar angle that is
  subtended from the $y$ axis. Finally $\phi$ is called the azimuth angle and is
  defined about the $y$ axis. To convert from cartesian to spherical we use:
    * $x = r\sin\theta\sin\phi$
    * $y = r\cos\theta$
    * $z = r\sin\theta\cos\phi$
* Cylindrical coordinates are used in graphics for texture coordinates, as well
  as specifying certain kinds of geometries.
* Spherical are used for the same reasons, and are also an important foundation
  for shading and rendering equations.

## Vectors, Points, and Normals

A vector is a *directed line segment* and is defined by its length and
direction. In 3D, we represent vectors as a triplet, so $v \in \mathbb{R}^3$.
For vectors, we define the following properties and operations:

* Length,
* Addition and subtraction,
* Scalar multiplication (commutative),
* Dot (or inner) product,
* Cross product.

The dot product can be expressed as $u \cdot v = \vert u\vert \vert v \vert \cos
\theta$. If we assume $u, v$ as unit vectors, then the dot product is the cosine
of the angle between both vectors. This definition is particularly important in
rendering equations. Recall that a unit vector is a vector with length 1. We can
normalize a vector by dividing each element by its length.

Points have the same representation as 3D vectors, the only difference is that
the addition (or subtraction) of two points yields a vector. Similarly, we can
add vectors to points and obtain a *translation* on that point.

A normal is a vector that is perpendicular to a given surface. This property is
important, as normals need to be treated separately, especially when we
transform them, in order for them to retain their orthogonality to the surface. 

