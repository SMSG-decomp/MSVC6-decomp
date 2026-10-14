void __cdecl vector_release(int sym)

{
  counted_array_size(*(short *)(sym + 2));
  return;
}

