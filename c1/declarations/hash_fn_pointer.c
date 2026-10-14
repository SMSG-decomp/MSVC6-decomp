uint hash_fn_pointer(uint key)

{
  return key >> 2 & 0xfff;
}

