void __cdecl decl_define_variable(c1_symbol *sym)

{
  c1_symbol *sym_00;
  c1_node *pcVar1;
  uint uVar2;
  int no_dynamic;
  
  sym_00 = sym;
  if ((sym->entity & 0xffffff) == 0) {
    if (0x7ffffffe < g_next_entity_id) {
      diag_fatal_simple(0x37);
    }
    uVar2 = sym->entity ^ g_next_entity_id;
    g_next_entity_id = g_next_entity_id + 1;
    sym->entity = uVar2 & 0xffffff ^ sym->entity;
  }
  sym->flags4 = sym->flags4 | 4;
  decl_begin_initialized_definition(sym);
  if ((sym_00->type->code & 0x8f) != 0x83) {
    uVar2 = type_classify_class_form(sym_00->type,(int *)&sym);
    if (((uVar2 & 3) == 0) || ((((sym->detail).cls)->layout_flags3c & 1) == 0)) {
      pcVar1 = tree_new_int_constant(0);
      decl_finish_initialization(sym_00,pcVar1);
      return;
    }
  }
  init_begin(sym_00,'\0');
  no_dynamic = 0;
  pcVar1 = tree_new_int_constant(0);
  init_process_initializer(pcVar1,no_dynamic);
  init_finish(sym_00);
  return;
}

