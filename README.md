strgarrman
=========

A small utility I wrote pretty much as a proof of concept for masks based on arrays of unsigned longs.

As it was some time ago, I can only take a stab at what the title probably means: STRing ARRay MANipulator

Because of the strong focus on the mask method, its intended use is somewhat secondary, but it it can be used for
finding duplicates in an unordered array of strings. It all depeneds on the the comprison function that
one decides to define.

Initially the comparison function just checked to see if the strings shared at least their first letter. The use here would be
closer to clustering, some what rough, but fast.

ac3 works fine, but it needs cleaning up.


