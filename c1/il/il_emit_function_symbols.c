void __fastcall il_emit_function_symbols(int *scope)

{
  int *piVar1;
  int *piVar2;
  
  if (g_opt_Zg == '\0') {
    g_il_block_level = '\x01';
    il_emit_function_labels();
    piVar1 = (int *)scope[0x83];
    if (piVar1 == (int *)0x0) {
      g_il_block_level = '\x01';
      il_emit_symbol(0xd,(c1_symbol *)0x0);
      g_il_block_level = '\x02';
      il_emit_symbol(0xd,(c1_symbol *)0x0);
      piVar2 = scope;
    }
    else {
      do {
        (**(code **)(*piVar1 + 0x20))();
        piVar1 = (int *)piVar1[1];
        piVar2 = (int *)0x0;
      } while (piVar1 != (int *)0x0);
    }
    if (piVar2 != (int *)*scope) {
      il_emit_symbol(6,(c1_symbol *)0x0);
    }
  }
  return;
}

