void coff_write_dword_arg(uint32_t d)

{
  coff_write_bytes(&d,4);
  return;
}

