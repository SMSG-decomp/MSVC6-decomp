void __cdecl tu_emit_dynamic_initializers(void)

{
  c1_symbol *sym;
  c1_vector *pcVar1;
  c1_symbol *pcVar2;
  c1_u8 *pcVar3;
  int iVar4;
  c1_node *node;
  short sVar5;
  uint value;
  
  if (g_error_count != 0) {
    return;
  }
  if (((byte)g_compile_flags_c4 & 0x20) != 0) {
    func_definition_end('\x01');
  }
  iVar4 = tu_pending_function_slot(0);
  if ((iVar4 != 0) && (g_block_depth == '\0')) {
    tu_emit_pending_functions();
    if (((byte)g_compile_flags_c4 & 0x20) == 0) goto LAB_1044b464;
    func_abandon_definition();
  }
  if (((byte)g_compile_flags_c4 & 0x20) != 0) {
    func_definition_end('\x01');
  }
LAB_1044b464:
  if ((g_dynamic_initializer_functions != (c1_vector *)0x0) &&
     (g_dynamic_initializer_functions->count != 0)) {
    func_body_begin_generated((c1_symbol *)0x0);
    pcVar1 = g_dynamic_initializer_functions;
    sVar5 = 0;
    while ((pcVar1 != (c1_vector *)0x0 && ((int)sVar5 < (int)(uint)pcVar1->count))) {
      sym = pcVar1->data[sVar5];
      sVar5 = sVar5 + 1;
      node = expr_build_call_node(sym,(c1_node *)0x0,0,0,0,0);
      stmt_emit_expression(node);
      pcVar3 = g_arenas[0].cur;
      if (g_pch_create_explicit != 0) {
        value = ((sym->tail).fn.record)->unk14;
        g_arenas[0].cur = g_arenas[0].cur + 8;
        if (g_arenas[0].end < g_arenas[0].cur) {
          arena_grow(g_arenas);
        }
        pcVar2 = g_current_function;
        *(uint *)(pcVar3 + 4) = value;
        *(c1_symbol **)pcVar3 = pcVar2;
        ((sym->tail).fn.record)->unk14 = (c1_u32)pcVar3;
      }
    }
    init_emit_crt_initializer_pointer(g_current_function);
    func_definition_end('\0');
  }
  return;
}

