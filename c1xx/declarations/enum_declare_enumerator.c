void enum_declare_enumerator(void)

{
  uint uVar1;
  void *unaff_EBP;
  c1_symbol *in_stack_00000014;
  c1_sym_list *in_stack_00000018;
  int in_stack_0000001c;
  int level;
  
  diag_error(0x1ca);
  if ((g_current_enum->x28).enumerators != (c1_symtab *)0x0) {
    symtab_insert((g_current_enum->x28).enumerators,unaff_EBP,in_stack_00000014);
    if ((in_stack_00000014->entity & 0xffffff) == 0) {
      if (0x7ffffffe < g_next_entity_id) {
        diag_fatal_simple(0x37);
      }
      uVar1 = in_stack_00000014->entity ^ g_next_entity_id;
      g_next_entity_id = g_next_entity_id + 1;
      in_stack_00000014->entity = uVar1 & 0xffffff ^ in_stack_00000014->entity;
    }
    if ((in_stack_0000001c < 1) &&
       ((((in_stack_0000001c < 0 || (in_stack_00000018 < (c1_sym_list *)0x80000000)) &&
         (-2 < in_stack_0000001c)) &&
        ((-1 < in_stack_0000001c || ((c1_sym_list *)0x7fffffff < in_stack_00000018)))))) {
      uVar1 = 4;
    }
    else {
      uVar1 = 8;
    }
    if ((4 < uVar1) && (in_stack_0000001c != 0)) {
      if (g_ms_extensions == '\0') {
        level = 1;
      }
      else {
        level = 3;
      }
      diag_warning(level,0x155,in_stack_00000014);
    }
    (in_stack_00000014->x28).members = in_stack_00000018;
    g_enum_value._0_4_ = in_stack_00000018;
    g_enum_value._4_4_ = in_stack_0000001c;
    if ((g_browse_file != (char *)0x0) && ((g_block_depth == '\0' || (g_opt_FR_browse != 0)))) {
      (*g_il_emitter->vtbl->define_symbol)(g_il_emitter,in_stack_00000014);
    }
  }
  return;
}

