#Using a mutex for array writes

Simple example of mtuex.

Multiple threads writing to the same array can cause the array to have incorrect values.

Using a mutex when writing to the array avoids the array getting into an invalid state.



