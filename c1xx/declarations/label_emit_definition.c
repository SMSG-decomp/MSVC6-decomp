void __cdecl label_emit_definition(c1_node *labelref)

{
  void *pvVar1;
  
  pvVar1 = labelref->left;
  *(byte *)((int)pvVar1 + 2) = *(byte *)((int)pvVar1 + 2) | 4;
  *(c1_u8 *)((int)pvVar1 + 0x28) = g_block_depth;
  if (((*(byte *)((int)pvVar1 + 0x18) & 3) != 0) &&
     ((int)(uint)*(byte *)((int)pvVar1 + 0x29) <
      g_seh_finally_depth + g_seh_except_depth + g_seh_try_depth)) {
    diag_error(0x2c1,0x53,pvVar1);
  }
  *(char *)((int)pvVar1 + 0x29) =
       (char)g_seh_finally_depth + (char)g_seh_except_depth + (char)g_seh_try_depth;
  il_emit_tuple(0x29,labelref);
  return;
}

