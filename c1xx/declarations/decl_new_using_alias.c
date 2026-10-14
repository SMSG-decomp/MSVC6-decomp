c1_symbol * __thiscall
decl_new_using_alias(c1_scope_stack *scope,c1_symbol *using_sym,c1_symbol *target)

{
  fe_name **name;
  fe_name *pfVar1;
  bool bVar2;
  c1_symbol *key;
  byte bVar3;
  int *piVar4;
  c1_symbol *pcVar5;
  void *pvVar6;
  byte bVar7;
  c1_type *using_entry;
  c1_symbol *member_class;
  
  key = target;
  pcVar5 = using_sym;
  using_entry = (c1_type *)&using_sym->name;
  bVar3 = target->kind & 0x1f;
  name = &target->name;
  if ((bVar3 == 7) || (bVar3 == 6)) {
    target._0_1_ = '\x01';
  }
  else {
    if ((bVar3 == 0x1a) && ((**(byte **)target->type & 0x1f) == 7)) {
      pcVar5 = decl_new_using_alias_of_alias(scope,(byte *)name,target,using_sym,using_entry);
      return pcVar5;
    }
    target._0_1_ = '\0';
  }
  piVar4 = (int *)scope_stack_lookup_name(scope,name,(char)target);
  using_sym = (c1_symbol *)0x0;
  bVar2 = false;
  if ((g_class_depth < 0) || (((pcVar5->kind & 0x1f) != 0x1a && ((pcVar5->flags21 & 4) != 0)))) {
    pfVar1 = *name;
    pcVar5 = sym_take_free_record(0x10,pfVar1,0);
    if (pcVar5 == (c1_symbol *)0x0) {
      pcVar5 = arena_alloc(g_arenas,g_symbol_size_table[0x10] + 3 & 0xfffffffc);
      if (pcVar5 == (c1_symbol *)0x0) {
        pcVar5 = (c1_symbol *)0x0;
      }
      else {
        pcVar5 = sym_init_kind(pcVar5,'\x10',pfVar1,0);
      }
    }
  }
  else {
    pfVar1 = *name;
    pcVar5 = sym_take_free_record(0x11,pfVar1,0);
    if (pcVar5 == (c1_symbol *)0x0) {
      pcVar5 = arena_alloc(g_arenas,g_symbol_size_table[0x11] + 3 & 0xfffffffc);
      if (pcVar5 == (c1_symbol *)0x0) {
        pcVar5 = (c1_symbol *)0x0;
      }
      else {
        pcVar5 = sym_init_kind(pcVar5,'\x11',pfVar1,0);
      }
    }
    if ((key->kind & 0x1f) == 0x1a) {
      member_class = g_scope_vector->entries[*(short *)&key->type->extra];
    }
    else {
      member_class = g_scope_vector->entries[(short)key->scope_index];
    }
    using_sym = (c1_symbol *)&member_class->name;
    if ((c1_sym_link *)name == ((member_class->x28).members)->tail) {
      bVar2 = true;
    }
  }
  bVar3 = pcVar5->flags1;
  if ((key->kind & 0x1f) == 0x1a) {
    bVar3 = (*(byte *)(*(int *)key->type + 1) ^ bVar3) & 0x40 ^ bVar3;
    pcVar5->flags1 = bVar3;
    bVar3 = (*(byte *)(*(int *)key->type + 1) ^ bVar3) & 0x10 ^ bVar3;
    pcVar5->flags1 = bVar3;
    bVar3 = (*(byte *)(*(int *)key->type + 1) ^ bVar3) & 0x20 ^ bVar3;
    pcVar5->flags1 = bVar3;
    bVar7 = *(byte *)(*(int *)key->type + 1);
  }
  else {
    bVar3 = (key->flags1 ^ bVar3) & 0x40 ^ bVar3;
    pcVar5->flags1 = bVar3;
    bVar3 = (key->flags1 ^ bVar3) & 0x10 ^ bVar3;
    pcVar5->flags1 = bVar3;
    bVar3 = (key->flags1 ^ bVar3) & 0x20 ^ bVar3;
    pcVar5->flags1 = bVar3;
    bVar7 = key->flags1;
  }
  pcVar5->flags1 = (bVar7 ^ bVar3) & 3 ^ bVar3;
  if ((key->scope_index != 0) &&
     (g_scope_vector->entries[(short)key->scope_index] != (c1_symbol *)0x0)) {
    sym_inherit_scope_index(pcVar5,&g_scope_vector->entries[(short)key->scope_index]->kind);
  }
  if ((key->flags2 & 0x20) == 0) {
    if ((key->flags2 & 0x40) == 0) goto LAB_10438239;
    pvVar6 = sym_hiding_partner(key);
    pcVar5->flags2 = pcVar5->flags2 | 0x40;
    symtab_15dc_insert(pvVar6,pcVar5);
    bVar3 = key->flags2 & 0xbf;
  }
  else {
    pvVar6 = sym_hiding_partner(key);
    pcVar5->flags2 = pcVar5->flags2 | 0x20;
    symtab_15dc_insert(pcVar5,pvVar6);
    bVar3 = key->flags2 & 0xdf;
  }
  key->flags2 = bVar3;
LAB_10438239:
  pcVar5->next = key->next;
  *piVar4 = (int)&pcVar5->name;
  if (bVar2) {
    *(fe_name ***)(*(int *)&using_sym->storage + 8) = &pcVar5->name;
  }
  pcVar5->type = using_entry;
  using_entry->base = (c1_type *)name;
  key->next = (c1_symbol *)0x0;
  return pcVar5;
}

