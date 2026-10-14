void __fastcall reader_check_binary_index(c2_tuple *a,c2_tuple *b,int ptr_ok)

{
  if (b->kind == '\a') {
    reader_check_array_index(a);
  }
  if (a->kind == '\a') {
    reader_check_array_index(b);
  }
  if (ptr_ok == 0) {
    if (((1 << (byte)(b->type >> 0xc) & 0xeU) != 0) && ((b->type & 0xf000) != 0x3000)) {
      reader_check_array_index(a);
    }
    if (((1 << (byte)(a->type >> 0xc) & 0xeU) != 0) && ((a->type & 0xf000) != 0x3000)) {
      reader_check_array_index(b);
    }
  }
  return;
}

