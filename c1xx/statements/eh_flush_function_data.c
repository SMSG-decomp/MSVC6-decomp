void __cdecl eh_flush_function_data(void)

{
  eh_emit_pending_data_objects();
  PTR_104d2cb8 = (c1_vector *)0x0;
  PTR_104d2cbc = (c1_vector *)0x0;
  return;
}

