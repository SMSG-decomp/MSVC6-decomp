byte * __thiscall decl_redeclare_beside_class_name(c1_declarator *d,byte *old)

{
  char cVar1;
  c1_type *pcVar2;
  c1_type *pcVar3;
  c1_sym_list *pcVar4;
  uint uVar5;
  byte bVar6;
  c1_symbol *pcVar7;
  uint uVar8;
  short n;
  
  bVar6 = old[2] & 0x10;
  if ((bVar6 != 0) && ((d->flags55 & 4) != 0)) {
    pcVar2 = d->type;
    if (pcVar2 == *(c1_type **)(old + 0x14)) {
      return old;
    }
    if ((*old & 0x1f) == 4) {
      if ((pcVar2->code & 0x300) == 0) {
        pcVar7 = (c1_symbol *)0x0;
      }
      else {
        pcVar7 = (pcVar2->extra).cls;
      }
      if (pcVar7 == (c1_symbol *)old) {
        cVar1 = (char)pcVar2->code;
        pcVar3 = pcVar2;
        while (cVar1 < '\0') {
          pcVar3 = pcVar3->base;
          cVar1 = (char)pcVar3->code;
        }
        if ((pcVar3->flags == 0) || (pcVar2->flags == (*(c1_type **)(old + 0x14))->flags)) {
          return old;
        }
      }
    }
    return (byte *)0x0;
  }
  if (bVar6 == 0) {
    if ((d->flags55 & 4) == 0) {
      return (byte *)0x0;
    }
    if ((old[2] & 0x10) != 0) goto LAB_1047a791;
    if ((d->spec[0] & 7) != 7) goto LAB_1047a7aa;
    n = 0x17a;
  }
  else {
LAB_1047a791:
    if ((old[0x20] & 7) != 7) goto LAB_1047a7aa;
    n = 0x179;
  }
  diag_error(n,old);
LAB_1047a7aa:
  if ((old[2] & 0x20) != 0) {
    return old;
  }
  old[2] = old[2] | 0x20;
  pcVar7 = sym_new_from_declarator(d,0xffffffff);
  d->sym = pcVar7;
  if ((d->kind == 7) || (d->kind == 8)) {
    pcVar7 = sym_new_alias_record(pcVar7);
  }
  else {
    if (0x7ffffffe < g_next_entity_id) {
      diag_fatal_simple(0x37);
    }
    uVar5 = d->sym->entity;
    uVar8 = uVar5 ^ g_next_entity_id;
    g_next_entity_id = g_next_entity_id + 1;
    d->sym->entity = uVar8 & 0xffffff ^ uVar5;
    pcVar7 = d->sym;
  }
  pcVar7->flags3 = (old[3] ^ pcVar7->flags3) & 8 ^ pcVar7->flags3;
  pcVar7->next = *(c1_symbol **)(old + 0xc);
  pcVar7->flags2 = pcVar7->flags2 | 0x40;
  symtab_15dc_insert(old,pcVar7);
  *(fe_name ***)(old + 0xc) = &pcVar7->name;
  if ((-1 < g_class_depth) &&
     (pcVar4 = ((g_class_def_stack[g_class_depth].cls)->x28).members,
     pcVar4->tail == (c1_sym_link *)(old + 8))) {
    pcVar4->tail = (c1_sym_link *)&pcVar7->name;
  }
  return &d->sym->kind;
}

