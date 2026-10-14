void __fastcall decl_record_reset_default_int(c1_decl_spec_scan *scan)

{
  int iVar1;
  c1_u8 *pcVar2;
  uint *dst;
  
  scan->basic_type = 0;
  scan->type_sym = (c1_symbol *)0x0;
  scan->named_type = (c1_type *)0x0;
  scan->result = (c1_u8 *)0x0;
  g_yylval_spec_insert_fn = (void *)0x0;
  g_yylval_spec_type_sym = (c1_symbol *)0x0;
  pcVar2 = scan->spec;
  g_yylval_spec_type = g_type_int;
  *pcVar2 = *pcVar2 | 0x10;
  dst = &g_yylval;
  for (iVar1 = 6; iVar1 != 0; iVar1 = iVar1 + -1) {
    *dst = *(uint *)pcVar2;
    pcVar2 = pcVar2 + 4;
    dst = dst + 1;
  }
  return;
}

