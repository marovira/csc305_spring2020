# Specular Reflection

## Quick Review

Before we introduce a new BRDF, let's do a quick recap of what we have. First,
let's review the components of the Lambertian BRDF:

| **BRDF** | $\rho_{hh}$ | $f_{r, d}$ |
|----------|-------------|------------|
| Lambertian | $k_d c_d$ | $k_d c_d / \pi$ |

Now, let's look at the $L_i$ for each of the lights that we have
previously defined:

| **Light** | $L_i$ |
|-----------|-------|
| Directional | $f_r(p, l, \omega_o) \star l_s c_l \cos\theta_l$ | 
| Point | $f_r(p, l, \omega_o) \star l_s c_l \cos\theta_l$ |

Note that here the point light has attenuation turned off. Now for the
directional light, $l$ is given by the direction of the light itself, whereas
for the point light, $l = p_l - p$ where $p_l$ is the location of the light.

Now recall the rendering equation

$$
L_o(p, \omega_o) = L_e(p, \omega_o) + \int_{2\pi^+} f_r(p, \omega_i, \omega_o)
L_i(p, \omega_i) \cos\theta_i d\omega_i
$$

From here, we derived the following expression for diffuse shading:

$$
L_o(p, \omega_o) = k_a c_d \star (l_s c_l) + \sum_{j = 1}^n \frac{k_d c_d}{\pi}
\star (l_{s, j} c_{l, j})(n \cdot l_j)
$$

Recall that if a surface is determined by more than one BRDF, then the total
radiance for that surface is the sum of the BRDFs. With this in mind, we are now
ready to begin discussing specular reflection.

We can make materials look shiny by allowing them to reflect light that's
focused around the direction of mirror-reflection. This glossy specular
reflection results in specular highlights on the surface, which are smeared out
reflections of the light sources themselves. If they are bright enough, then
they are the colour of the lights, which are usually white.

## Modeling

To model specular reflection, we need an expression for the unit vector $r$ in
the direction of mirror reflection at the point $p$ given an incoming light
direction $l$ and a normal $n$. These two vectors and the normal are all in the
same plane, called the *plane of incidence*. According to the *law of
reflection*, the angle subtended by $l$ and $r$ is equal, so we will use
$\theta_i$ for both. Note that $r$ is not necessarily the same as the viewing
direction $\omega_o$, which also doesn't have to be in the plane of incidence.

To derive $r$, we note that since $l$, $r$, and $n$ are complanar, then $r$ must
be a linear combination of $l$ and $n$:

$$
\mathbf{r} = a \mathbf{l} + b\mathbf{n}
$$
{#eq:eq15_1}

where $a, b$ are numbers. Since we have two unknowns, we require two equations
to determine their values. First notice that the projections of $r$ and $l$ onto
$n$ are the same. Taking the dot product of both sides in [@eq:eq15_1] with $n$
gives

$$
\mathbf{r} \cdot \mathbf{n} = a\mathbf{l} \cdot \mathbf{n} + b\mathbf{n} \cdot
\mathbf{n}
$$

so that

$$
(1 - a) \mathbf{l} \cdot \mathbf{n} = b
$$
{#eq:eq15_2}

Now consider the unit direction $\mathbf{n}^{\perp}$ that is perpendicular to
$\mathbf{n}$ and lies in the plane of incidence. Note that these two vectors
form an orthonormal basis in this plane. The projections of $r$ and $l$ onto
$\mathbf{n}^{\perp}$ are negatives of each other. Taking the dot product with
[@eq:eq15_1] with $\mathbf{n}^{\perp}$:

$$
\mathbf{r} \cdot \mathbf{n}^{\perp} = a\mathbf{l} \cdot \mathbf{n}^{\perp} +
b\mathbf{n} \cdot \mathbf{n}^{\perp}
$$

leads to

$$
a = -1
$$
{#eq:eq15_3}

We can now combine [@eq:eq15_1], [@eq:eq15_2] and [@eq:eq15_3] to obtain the
following expression for $r$:

$$
\mathbf{r} = -\mathbf{l} + 2(\mathbf{n} \cdot \mathbf{l}) \mathbf{n}
$$
{#eq:eq15_4}

Note that this vector is unit by construction. Now that we have the direction of
reflection, we need a way to model the way reflected radiance decreases as the
angle $\alpha$ between $r$ and $\omega_o$ increases. 

Phong modelled this with the expression $(\cos\alpha)^e = (\mathbf{r} \cdot
\omega_o)^e$ where the *Phong exponent* $e \geq 0$. This number allows us to
control the size of the specular highlights. Using Phong's model for specular
reflection, we obtain the following for the reflected radiance of a single
directional light:

$$
L_o(p, \omega_o) = k_s(\mathbf{r} \cdot \omega_o)^e l_s c_l
$$
{#eq:eq15_5}

where $k_s$ is the *coefficient of specular reflection*. Now it is important to
note that this is an empirical model and is not reciprocal nor does it conserve
energy. Fortunately, this can be fixed. One of the problems with [@eq:eq15_5]
is that there is no $\cos\theta_l = \mathbf{n} \cdot \mathbf{l}$ although it is
present in the rendering equation. A reciprocal glossy specular BRDF is of the
form

$$
f_{r, s} (l, \omega_o) = k_s(\mathbf{r} \cdot \omega_o)^e
$$
{#eq:eq15_6}

This satisfies the reciprocity condition for all $\mathbf{l}, \omega_o$. With
the BRDF in [@eq:eq15_6], the reflected specular radiance is then

$$
L_o(p, \omega_o) = k_s(\mathbf{r} \cdot \omega_o)^e l_s c_l(\mathbf{n}\cdot
\mathbf{l})
$$
{#eq:eq15_7}

We can make the BRDF energy conserving by enforcing the condition $k_d + k_s <
1.0$. The reason that although $k_d$ and $k_s$ specify different kinds of
reflection, they both come from the same light source. We therefore have the
following expression for the sum of the ambient, diffuse, and specular
reflection for $n$ point and directional lights:

$$
L_o(p, \omega_o) = k_a c_d \star(l_s c_l) + \sum_{j = 1}^n \frac{k_d c_d}{\pi}
\star (l_{s_j} c_{l_j})(\mathbf{n} \cdot \mathbf{l}_j) + \sum_{j = 1}^n
k_s(\mathbf{r}_j \cdot \omega_o)^e (l_{s_j} c_{l_j})(\mathbf{n} \cdot
\mathbf{l}_j)
$$
{#eq:eq15_8}

An issue with direct illumination is that the angle between $\mathbf{r}$ and
$\omega_o$ can be greater than $\pi / 2$. Because this results in a negative
value of $\mathbf{r} \cdot \omega_o$, we must clamp it to positive values in
[@eq:eq15_8]

Note that if we want the highlights to have colour, we simply have to multiply
$k_s (\mathbf{r}_j \cdot \omega_o)^e$ by $c_s$.


## Viewer Dependence

Based on the formula for diffuse shading, we can see that it varies based only
on the angle between the incoming radiance and the surface normal. Therefore,
this type of shading is called *viewer-independent* shading. In contrast, if we
look at the specular highlights in the real world move around as we look at
objects. This is due to the fact that the specular highlight is always centred
on the direction of mirror reflection which is defined by the light, the
surface, and the viewer. Therefore, specular reflection is *viewer-dependent*
shading.

## Other Reflection Models

Blinn made the following simple modification to Phong's specular model:

$$
f_{r, s}(l, \omega_o) = k_s (\mathbf{n} \cdot \mathbf{h})^e
$$

Where $\mathbf{h} = (\mathbf{l} + \omega_o) / \vert \mathbf{l} + \omega_o \vert$
is called the *halfway vector* between $\mathbf{l}$ and $\omega_o$. The original
motivation for this was efficiency as it does not require the full computation
of the reflection vector, and for a directional light with orthographic viewing,
$\mathbf{h}$ is constant. That being said, the *Blinn-Phong* model is still
widely used today. Note that due to the fact that the angle subtended by
$\mathbf{h}$ is not euqal to $\alpha$, we require larger exponents $e$ in order
to match the same effect that we would get from Phong shading.
