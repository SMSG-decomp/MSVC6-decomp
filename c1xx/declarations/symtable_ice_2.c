c1_symbol * __cdecl symtable_ice_2(void *name,c1_symbol *sym,c1_symbol *qualified)

{
  c1_u8 cVar1;
  c1_type *pcVar2;
  c1_u8 *pcVar3;
  c1_u16 cVar4;
  c1_symbol *pcVar5;
  c1_symbol *pcVar6;
  c1_symbol *pcVar7;
  int arena;
  c1_arena *a;
  
  cVar1 = g_current_scope->current->kind;
  if ((cVar1 == '\0') || (cVar1 == 0xff)) {
    arena = 0;
  }
  else {
    arena = 4;
  }
  pcVar5 = sym_take_free_record(0x1a,name,arena);
  if (pcVar5 == (c1_symbol *)0x0) {
    pcVar5 = arena_alloc(g_arenas + arena,g_symbol_size_table[0x1a] + 3 & 0xfffffffc);
    if (pcVar5 == (c1_symbol *)0x0) {
      pcVar5 = (c1_symbol *)0x0;
    }
    else {
      pcVar5 = sym_init_kind(pcVar5,'\x1a',name,arena);
    }
  }
  a = g_arenas + arena;
  pcVar2 = (c1_type *)a->cur;
  pcVar3 = g_arenas[arena].end;
  a->cur = (c1_u8 *)&pcVar2->debug_index;
  if (pcVar3 < &pcVar2->debug_index) {
    arena_grow(a);
  }
  pcVar5->type = pcVar2;
  if ((sym->kind & 0x1f) == 0x1a) {
    cVar4 = sym->type->flags;
    pcVar2->code = sym->type->code;
    pcVar2->flags = cVar4;
  }
  else {
    *(c1_symbol **)pcVar2 = sym;
  }
  *(undefined2 *)&pcVar5->type->extra = 0;
  *(undefined1 *)((int)&pcVar5->type->extra + 2) = 0;
  pcVar5->type->base = (c1_type *)0x0;
  pcVar5->position = g_token_position;
  if (g_current_scope->current->kind == 0xff) {
    if (g_current_scope->current->kind < 0xfb) {
      diag_fatal(1,"symtable.inl",0xbb9);
    }
    *(c1_u16 *)&pcVar5->type->extra =
         ((((g_current_scope->current->body).cls)->detail).cls)->scope_index;
    if ((sym->kind & 0x1f) == 0x1a) {
      pcVar6 = sym_new_scoped_copy((c1_symbol *)sym->type->base,0);
      pcVar7 = sym_new_scoped_copy(qualified,0);
      lookup_qualifier_chain_splice
                (*(c1_keyed_cell **)pcVar6->type,(c1_keyed_cell *)**(undefined4 **)pcVar7->type);
      pcVar5->type->base = (c1_type *)pcVar6;
    }
    else {
      pcVar6 = sym_new_scoped_copy(qualified,0);
      pcVar5->type->base = (c1_type *)pcVar6;
    }
    pcVar5->flags2 = (g_class_def_stack[g_class_depth].flags ^ pcVar5->flags2) & 3 ^ pcVar5->flags2;
    if (((name == g_name_ctor) || (name == g_name_dtor)) || (name == g_name_operator_assign)) {
      *(undefined1 *)((int)&pcVar5->type->extra + 2) = 1;
    }
  }
  return pcVar5;
}

