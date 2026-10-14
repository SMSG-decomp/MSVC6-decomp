ulonglong __cdecl il_read_8_bytes(void)

{
  ulonglong uStack_8;
  
  il_read_bytes(8,(char *)&uStack_8);
  return uStack_8;
}

