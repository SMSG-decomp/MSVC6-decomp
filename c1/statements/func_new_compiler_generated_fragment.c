c1_node * __cdecl
func_new_compiler_generated_fragment
          (void *segment,char named,c1_symbol *object,c1_node *result,c1_u8 saved_il_block_level,
          c1_u8 saved_block_depth)

{
  c1_node *pcVar1;
  
  if (segment != (void *)0x0) {
    if (named == '\0') {
      sym_set_or_clear_segment(object,(int)segment);
    }
    else {
      sym_set_segment_checked(object,segment);
    }
  }
  if ((((g_current_function != (c1_symbol *)0x0) && ((g_current_function->flags22 & 0xc) != 0)) &&
      (((g_current_function->flags21 & 1) != 0 || ((g_compile_flags_c4 & 0x200) != 0)))) &&
     ((g_current_function->flags22 & 4) != 0)) {
    object->flags22 = object->flags22 | 4;
  }
  if (named == '\0') {
    object->flags2 = (g_block_depth != '\0') << 1 | object->flags2 & 0xfd;
  }
  else {
    (*g_current_scope->file_scope->vtbl->insert)(g_current_scope->file_scope,object);
  }
  pcVar1 = tree_new_symbol_ref(object);
  pcVar1->type = object->type;
  init_emit_relocations_to_buffer(object,result);
  il_emit_global_symbol((int *)&object->name);
  pcVar1->kind = '\x04';
  pcVar1->op = '\x06';
  g_il_block_level = saved_il_block_level;
  g_block_depth = saved_block_depth;
  return pcVar1;
}

