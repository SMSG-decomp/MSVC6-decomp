uint32_t __cdecl coff_writer_timestamp(void)

{
  uint32_t uStack_4;
  
  if (g_opt_brepro == 0) {
    time((time_t *)&uStack_4);
    return uStack_4;
  }
  return 0;
}

