int __cdecl decl_warn_benign_type_redefinition(c1_u16 code1,c1_u16 code2)

{
  if (code1 == code2) {
    return 1;
  }
  if ((&g_type_rank_table)[code1 & 0xf] == (&g_type_rank_table)[code2 & 0xf]) {
    diag_warning(1,0x8e);
    return 1;
  }
  return 0;
}

