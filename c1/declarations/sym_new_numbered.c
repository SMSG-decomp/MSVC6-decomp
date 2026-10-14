c1_symbol * __cdecl sym_new_numbered(c1_symbol *sym,c1_declaration *decl)

{
  void *value;
  c1_u8 cVar1;
  c1_u8 cVar2;
  c1_u8 cVar3;
  byte bVar4;
  byte bVar5;
  uint uVar6;
  
  sym->type = decl->type;
  cVar1 = (decl->spec).inlining;
  cVar2 = (decl->spec).declspec;
  cVar3 = (decl->spec).allocate;
  sym->storage = (decl->spec).storage;
  sym->flags21 = cVar1;
  sym->flags22 = cVar2;
  sym->flags23 = cVar3;
  if ((((sym->kind & 0x1f) == 7) || (bVar4 = sym->kind & 0x1f, bVar4 == 8)) || (bVar4 == 6)) {
    (sym->x2c).function_flags = (decl->spec).flags8 >> 1 & 1 ^ (sym->x2c).function_flags & 0xfe;
  }
  if (((decl->spec).allocate & 1) == 0) {
    sym_set_or_clear_segment_2(sym,(void *)0x0);
  }
  else {
    value = (decl->spec).segment;
    if (value == (void *)0x0) {
      sym->flags23 = sym->flags23 & 0xfe;
    }
    else {
      sym_set_segment(sym,value);
    }
  }
  bVar4 = (decl->flags2d ^ sym->flags1) & 4 ^ sym->flags1;
  sym->flags1 = bVar4;
  bVar5 = (decl->flags2c & 0x20) << 1;
  sym->flags1 = bVar5 | bVar4 & 0xbf;
  sym->flags1 = decl->flags2c >> 3 & 1 | bVar5 | bVar4 & 0xbe;
  sym->flags3 = (sym->flags3 ^ decl->flags2c) & 4 ^ sym->flags3;
  sym->flags2 = decl->flags2f >> 4 & 2 | sym->flags2 & 0xfd;
  sym->flags1 = decl->flags2c >> 3 & 2 | sym->flags1 & 0xfd;
  if ((sym->entity & 0xffffff) == 0) {
    if (0x7ffffffe < g_next_entity_id) {
      diag_fatal_simple(0x37);
    }
    uVar6 = sym->entity ^ g_next_entity_id;
    g_next_entity_id = g_next_entity_id + 1;
    sym->entity = uVar6 & 0xffffff ^ sym->entity;
  }
  sym->position = decl->position;
  return sym;
}

