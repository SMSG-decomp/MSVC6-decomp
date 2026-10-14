c1_symbol * __thiscall
decl_new_using_alias_of_alias
          (c1_scope_stack *scope,byte *name,c1_symbol *target,c1_symbol *using_sym,
          c1_type *using_entry)

{
  c1_symbol *pcVar1;
  bool bVar2;
  byte bVar3;
  c1_symbol *pcVar4;
  void *pvVar5;
  byte bVar6;
  int *piStack00000010;
  fe_name **ppfStack0000001c;
  
  piStack00000010 = (int *)scope_stack_lookup_name(scope,name,'\x01');
  ppfStack0000001c = (fe_name **)0x0;
  bVar2 = false;
  if ((g_class_depth < 0) || (((using_sym->kind & 0x1f) != 0x1a && ((using_sym->flags21 & 4) != 0)))
     ) {
    pvVar5 = *(void **)name;
    pcVar4 = sym_take_free_record(0x10,pvVar5,0);
    if (pcVar4 == (c1_symbol *)0x0) {
      pcVar4 = arena_alloc(g_arenas,g_symbol_size_table[0x10] + 3 & 0xfffffffc);
      if (pcVar4 == (c1_symbol *)0x0) {
        pcVar4 = (c1_symbol *)0x0;
      }
      else {
        pcVar4 = sym_init_kind(pcVar4,'\x10',pvVar5,0);
      }
    }
  }
  else {
    pvVar5 = *(void **)name;
    pcVar4 = sym_take_free_record(0x11,pvVar5,0);
    if (pcVar4 == (c1_symbol *)0x0) {
      pcVar4 = arena_alloc(g_arenas,g_symbol_size_table[0x11] + 3 & 0xfffffffc);
      if (pcVar4 == (c1_symbol *)0x0) {
        pcVar4 = (c1_symbol *)0x0;
      }
      else {
        pcVar4 = sym_init_kind(pcVar4,'\x11',pvVar5,0);
      }
    }
    if ((target->kind & 0x1f) == 0x1a) {
      pcVar1 = g_scope_vector->entries[*(short *)&target->type->extra];
    }
    else {
      pcVar1 = g_scope_vector->entries[(short)target->scope_index];
    }
    ppfStack0000001c = &pcVar1->name;
    if ((c1_sym_link *)name == ((pcVar1->x28).members)->tail) {
      bVar2 = true;
    }
  }
  bVar3 = pcVar4->flags1;
  if ((target->kind & 0x1f) == 0x1a) {
    bVar3 = (*(byte *)(*(int *)target->type + 1) ^ bVar3) & 0x40 ^ bVar3;
    pcVar4->flags1 = bVar3;
    bVar3 = (*(byte *)(*(int *)target->type + 1) ^ bVar3) & 0x10 ^ bVar3;
    pcVar4->flags1 = bVar3;
    bVar3 = (*(byte *)(*(int *)target->type + 1) ^ bVar3) & 0x20 ^ bVar3;
    pcVar4->flags1 = bVar3;
    bVar6 = *(byte *)(*(int *)target->type + 1);
  }
  else {
    bVar3 = (target->flags1 ^ bVar3) & 0x40 ^ bVar3;
    pcVar4->flags1 = bVar3;
    bVar3 = (target->flags1 ^ bVar3) & 0x10 ^ bVar3;
    pcVar4->flags1 = bVar3;
    bVar3 = (target->flags1 ^ bVar3) & 0x20 ^ bVar3;
    pcVar4->flags1 = bVar3;
    bVar6 = target->flags1;
  }
  pcVar4->flags1 = (bVar6 ^ bVar3) & 3 ^ bVar3;
  if ((target->scope_index != 0) &&
     (g_scope_vector->entries[(short)target->scope_index] != (c1_symbol *)0x0)) {
    sym_inherit_scope_index(pcVar4,&g_scope_vector->entries[(short)target->scope_index]->kind);
  }
  if ((target->flags2 & 0x20) == 0) {
    if ((target->flags2 & 0x40) == 0) goto LAB_10438239;
    pvVar5 = sym_hiding_partner(target);
    pcVar4->flags2 = pcVar4->flags2 | 0x40;
    symtab_15dc_insert(pvVar5,pcVar4);
    bVar3 = target->flags2 & 0xbf;
  }
  else {
    pvVar5 = sym_hiding_partner(target);
    pcVar4->flags2 = pcVar4->flags2 | 0x20;
    symtab_15dc_insert(pcVar4,pvVar5);
    bVar3 = target->flags2 & 0xdf;
  }
  target->flags2 = bVar3;
LAB_10438239:
  pcVar4->next = *(c1_symbol **)(name + 4);
  *piStack00000010 = (int)&pcVar4->name;
  if (bVar2) {
    ((c1_symbol_x28 *)(ppfStack0000001c + 8))->members->tail = (c1_sym_link *)&pcVar4->name;
  }
  pcVar4->type = using_entry;
  using_entry->base = (c1_type *)name;
  name[4] = 0;
  name[5] = 0;
  name[6] = 0;
  name[7] = 0;
  return pcVar4;
}

