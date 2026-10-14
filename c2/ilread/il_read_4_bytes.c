uint32_t __cdecl il_read_4_bytes(void)

{
  uint32_t uStack_4;
  
  il_read_bytes(4,(char *)&uStack_4);
  return uStack_4;
}

