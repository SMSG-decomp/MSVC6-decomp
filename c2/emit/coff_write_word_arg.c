void coff_write_word_arg(uint16_t w)

{
  coff_write_bytes(&w,2);
  return;
}

