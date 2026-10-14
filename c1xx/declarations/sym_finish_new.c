c1_symbol * __thiscall sym_finish_new(c1_symbol *sym,c1_declarator *d)

{
  c1_u8 cVar1;
  c1_u8 cVar2;
  c1_u8 cVar3;
  byte bVar4;
  uint uVar5;
  uint *declspec_copy;
  uint *declspec_src;
  
  cVar1 = d->spec[1];
  cVar2 = d->spec[2];
  cVar3 = d->spec[3];
  sym->storage = d->spec[0];
  sym->flags21 = cVar1;
  sym->flags22 = cVar2;
  sym->flags23 = cVar3;
  if ((((sym->kind & 0x1f) == 7) || (bVar4 = sym->kind & 0x1f, bVar4 == 8)) || (bVar4 == 6)) {
    *(byte *)((int)&sym->tail + 0xb) =
         d->spec[0x14] >> 3 & 1 ^ *(byte *)((int)&sym->tail + 0xb) & 0xfe;
  }
  if (((d->spec[3] & 1) == 0) || (*(void **)(d->spec + 4) == (void *)0x0)) {
    sym->flags23 = sym->flags23 & 0xfe;
  }
  else {
    sym_set_segment(sym,*(void **)(d->spec + 4));
  }
  if ((d->spec[1] & 0x40) == 0) {
    sym_attach_declspec_record(sym,(uint *)0x0);
  }
  else {
    declspec_src = *(uint **)(d->spec + 0xc);
    if (declspec_src == (uint *)0x0) {
      sym->flags21 = sym->flags21 & 0xbf;
    }
    else {
      declspec_copy = arena_alloc(g_arenas,0x10);
      if (declspec_copy == (uint *)0x0) {
        sym_attach_extra(sym,(void *)0x0);
      }
      else {
        *declspec_copy = *declspec_src;
        declspec_copy[1] = declspec_src[1];
        declspec_copy[2] = declspec_src[2];
        declspec_copy[3] = declspec_src[3];
        sym_attach_extra(sym,declspec_copy);
      }
    }
  }
  if (*(void **)(d->spec + 8) == (void *)0x0) {
    sym->flags23 = sym->flags23 & 0x7f;
  }
  else {
    symtab_1b40_insert(sym,*(void **)(d->spec + 8));
  }
  sym->flags2 = (d->flags55 & 4) << 2 | sym->flags2 & 0xef;
  sym->flags3 = d->flags54 >> 5 & 1 | sym->flags3 & 0xfe;
  sym->flags2 = d->flags54 >> 1 & 4 | sym->flags2 & 0xfb;
  sym->flags4 = (sym->flags4 ^ d->flags54) & 4 ^ sym->flags4;
  sym->flags3 = d->flags57 >> 2 & 8 | sym->flags3 & 0xf7;
  sym->flags2 = d->flags54 >> 1 & 8 | sym->flags2 & 0xf7;
  sym->flags1 = (sym->flags1 ^ d->flags54) & 3 ^ sym->flags1;
  if ((sym->entity & 0xffffff) == 0) {
    if (0x7ffffffe < g_next_entity_id) {
      diag_fatal_simple(0x37);
    }
    uVar5 = g_next_entity_id ^ sym->entity;
    g_next_entity_id = g_next_entity_id + 1;
    sym->entity = uVar5 & 0xffffff ^ sym->entity;
  }
  sym->position = d->position;
  return sym;
}

