# Midterm Review Questions

## Ray-Object Intersection

For each of the questions below, determine if the ray intersects the given
object. If it does, compute the value of $t$ at the point of intersection. You
may leave your answer in exact form.

1. Consider a triangle $T$ with vertices $x_0 = (-1, 0, 0), x_1 = (0, 1, 0), x_2
   = (1, 0, 0)$ and a ray $r(t) = o + t\mathbf{d}$ with $o = (0.5, 0.5, 1)$ and
   $\mathbf{d} = (0, 0, -1)$. Compute the information outlined above.
2. Consider an axis-aligned box $B$ defined by two points $p_0 = (-1, -1, -1),
   p_1 = (1, 1, 1)$ and a ray $r(t) = o + t \mathbf{d}$ with $o = (0, 0, 2)$ and
   $\mathbf{d} = (0, 0, -1)$. Compute the information outlined above.
3. Consider a sphere $S$ with centre $c = (1, 1, 0)$ and radius $r = 1$.
   Consider a ray $r(t) = o + t\mathbf{d}$ with $o = (-1, 1, 0)$ with
   $\mathbf{d} = (1, 0, 0)$. Compute the information outlined above.

## Multisampling

1. Generate 4 samples using $n$-rook sampling.
2. Generate 9 samples using Jittered sampling.

## Viewing Systems

1. Given a pinhole camera with $e = (-1, 1, 1)$, $l = (0, -1, 0)$ and
   $\mathbf{up} = (0, 1, 0)$, compute the orthonormal basis for this camera. You
   may leave your answer in exact form.
2. Given $d = 4$ and a viewing plane with dimensions $100 \times 100$, compute
   the ray $r(t) = o + t\mathbf{d}$ that passes through the pixel at $(60, 6)$
   with sample point $p = (0.5, 0.5f)$.

## Rendering Theory

1. Given $k_d = 0.5$ and $c_d = (0.5, 1.0, 0.5)$, evaluate $f_r(p, \omega_i,
   \omega_o)$ for the Lambertian BRDF.

## Transforms

1. Suppose you are given a matrix $T$ that contains a mixture of rotations,
   scaling, and translations in 3D space. Compute two matrices $S$ and $L$ where
   $S$ contains the scaling and rotation components of $T$ and $L$ contains the
   translation components of $T$.
