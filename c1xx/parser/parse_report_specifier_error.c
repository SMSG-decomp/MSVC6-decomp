void __cdecl parse_report_specifier_error(int n,c1_u32 *token_value)

{
  short n_00;
  uint uVar1;
  char *pcVar2;
  int iVar3;
  uint *puVar4;
  uint spec_args [6];
  
  uVar1 = spec_args[3];
  spec_args[3]._0_2_ = (short)n;
  n_00 = (short)spec_args[3];
  if ((*token_value & 0x10) == 0) {
    spec_args[5] = token_value[6];
    spec_args[4] = 0x54;
    spec_args[3] = n;
    spec_args[2] = 0x10472590;
    diag_error(n_00,0x54,(void *)spec_args[5]);
    return;
  }
  spec_args[5] = 0x1047259b;
  spec_args[3] = uVar1;
  spec_args[5] = format_buffer_acquire();
  spec_args[4] = 0x104725a1;
  format_buffer_free(spec_args[5]);
  puVar4 = spec_args;
  for (iVar3 = 6; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = *token_value;
    token_value = token_value + 1;
    puVar4 = puVar4 + 1;
  }
  iVar3 = format_decl_specifiers_text
                    (0,spec_args[0],(void *)spec_args[1],spec_args[2],spec_args[3],spec_args[4],
                     spec_args[5]);
  pcVar2 = format_buffer_text(iVar3);
  diag_error(n_00,0x73,pcVar2);
  spec_args[5] = 0x104725cf;
  format_buffer_leave();
  return;
}

