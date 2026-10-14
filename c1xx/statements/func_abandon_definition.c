void __cdecl func_abandon_definition(void)

{
  c1_symbol *fn;
  
  fn = g_current_function;
  func_definition_end('\0');
  func_body_begin_generated((c1_symbol *)0x0);
  func_emit_atexit_registration(fn);
  func_definition_end('\x01');
  return;
}

