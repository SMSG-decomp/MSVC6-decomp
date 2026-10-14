void __fastcall coff_write_byte_arg(uint8_t b)

{
  uint8_t b_copy;
  
  coff_write_bytes(&b_copy,1);
  return;
}

