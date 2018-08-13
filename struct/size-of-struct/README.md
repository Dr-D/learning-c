# size of struct

Had just assume that the size of a struct would be the size of each component int the struct.

The first time i tried this was with a string i.e. char[n] and an int as in the first example given 'TestSize.

'''
struct TestSize {
  char ch[1];
  int i;
};
'''

So I would have expected a size of 1 byte + 4 bytes, but the actual size is 8 bytes.

If we swap the compenents around we as in TestSize2 we still get a struct of size 8 bytes.

The last situation TestSize3
'''
struct TestSize {
  char ch[1];
  short s;
  int i;
};
'''

This gives a further clue as to what is going on. The compiler is padding the components to a size of 32 bits(4 bytes).

After doing some reading it looks like this is a compiler optimisation. You can of course rearrange your struct components to make the struct smaller. This is a compiler specific behaviour so may cause issues if different compilers are expecting data to have different layouts. It may be possible to turn this off using __attribute__((packed)).
