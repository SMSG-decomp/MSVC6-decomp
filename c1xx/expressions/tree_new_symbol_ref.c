c1_node * __cdecl tree_new_symbol_ref(c1_symbol *sym,char use_type)

{
  byte bVar1;
  c1_type *pcVar2;
  c1_symbol *pcVar3;
  c1_node *pcVar4;
  c1_node *pcVar5;
  c1_arena *a;
  int in_class_scope;
  c1_type local_10;
  
  if (sym == (c1_symbol *)0x0) {
    return (c1_node *)0x0;
  }
  a = g_arenas + g_expr_arena_index;
  pcVar5 = (c1_node *)a->cur;
  pcVar4 = (c1_node *)g_arenas[g_expr_arena_index].end;
  a->cur = &pcVar5[1].op;
  if (pcVar4 < pcVar5 + 1) {
    arena_grow(a);
  }
  pcVar5->op = '\x06';
  pcVar5->kind = '\x04';
  pcVar5->left = sym;
  if ((sym->kind & 0x1f) == 0x12) {
    sym = *(c1_symbol **)(*(int *)sym->type + 8);
  }
  if ((sym->flags3 & 4) != 0) {
    pcVar5->kind = '\f';
  }
  if ((sym->flags2 & 0x10) != 0) {
    pcVar5->kind = '\0';
    pcVar5->op = 0x98;
    pcVar5->type = sym->type;
    return pcVar5;
  }
  bVar1 = sym->kind & 0x1f;
  if (bVar1 == 0x1a) {
    local_10.base = (c1_type *)0x0;
    local_10.debug_index = 0;
    local_10.code = 0x80e;
    local_10.flags = 0;
    local_10.extra.cls = (c1_symbol *)0x0;
    pcVar2 = type_intern(&local_10);
    pcVar5->type = pcVar2;
    return pcVar5;
  }
  if ((((bVar1 == 0x10) || (bVar1 == 0x11)) || (bVar1 == 0x1b)) ||
     ((((bVar1 == 7 || (bVar1 == 8)) || (bVar1 == 6)) && (use_type == '\0')))) {
    local_10.code = 0x80c;
  }
  else {
    if ((bVar1 == 2) || (bVar1 == 3)) {
      local_10.base = (c1_type *)0x0;
      local_10.debug_index = 0;
      local_10.code = 0x80e;
      local_10.flags = 0;
      local_10.extra.cls = (c1_symbol *)0x0;
      pcVar2 = type_intern(&local_10);
      pcVar5->type = pcVar2;
      return pcVar5;
    }
    if (bVar1 != 0xf) {
      if (bVar1 == 5) {
        pcVar5->type = sym->type;
        return pcVar5;
      }
      if ((sym->flags5 & 4) != 0) {
        if (bVar1 == 0xb) {
          pcVar5->type = sym->type;
          pcVar2 = conv_array_to_pointer_type(pcVar5);
          pcVar5->type = pcVar2;
          return pcVar5;
        }
        if (bVar1 == 0xc) {
          pcVar5 = expr_array_to_pointer_tail(sym,pcVar5);
          return pcVar5;
        }
      }
      pcVar5->type = sym->type;
      if ((sym->flags23 & 1) == 0) {
        return pcVar5;
      }
      bVar1 = sym->kind & 0x1f;
      if (bVar1 == 7) {
        return pcVar5;
      }
      if (bVar1 == 8) {
        return pcVar5;
      }
      pcVar3 = sym_segment_record(sym);
      if ((pcVar3->kind & 0x1f) == 0xe) {
        return pcVar5;
      }
      pcVar2 = pcVar5->type;
      in_class_scope = 0;
      pcVar3 = sym_segment_record(sym);
      pcVar4 = expr_reference_named_entity(pcVar3,in_class_scope);
      pcVar5 = tree_new_node(']',pcVar5,pcVar4,pcVar2);
      return pcVar5;
    }
    local_10.code = 0x80e;
  }
  local_10.debug_index = 0;
  local_10.extra.cls = (c1_symbol *)0x0;
  local_10.base = (c1_type *)0x0;
  local_10.flags = 0;
  pcVar2 = type_intern(&local_10);
  pcVar5->type = pcVar2;
  return pcVar5;
}

