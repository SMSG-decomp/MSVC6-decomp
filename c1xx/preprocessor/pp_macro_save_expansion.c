void __cdecl pp_macro_save_expansion(uint *start,int end)

{
  byte *pbVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  
  uVar3 = end - (int)start;
  if (g_macro_arg_buffer_limit <= g_macro_arg_cursor + uVar3) {
    pp_define_check_size
              ((uint)(g_macro_arg_cursor + uVar3),g_macro_arg_buffer,
               (int *)&g_macro_arg_buffer_limit);
  }
  puVar4 = (uint *)(g_macro_arg_cursor + 2);
  for (uVar2 = uVar3 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
    *puVar4 = *start;
    start = start + 1;
    puVar4 = puVar4 + 1;
  }
  for (uVar2 = uVar3 & 3; pbVar1 = g_macro_arg_cursor, uVar2 != 0; uVar2 = uVar2 - 1) {
    *(byte *)puVar4 = (byte)*start;
    start = (uint *)((int)start + 1);
    puVar4 = (uint *)((int)puVar4 + 1);
  }
  g_macro_arg_cursor[uVar3 + 2] = 0;
  pbVar1[uVar3 + 3] = 0x41;
  pbVar1 = pbVar1 + uVar3 + 4;
  *(short *)g_macro_arg_cursor = (short)pbVar1 - (short)g_macro_arg_cursor;
  g_macro_arg_cursor = pbVar1;
  return;
}

