void __cdecl browse_record_fill_definition(c1_browse_record *rec,c1_symbol *sym)

{
  char cVar1;
  c1_type *pcVar2;
  bool bVar3;
  byte bVar4;
  byte bVar5;
  ushort uVar6;
  
  if ((g_browse_symbol_kind_excluded[sym->kind & 0x1f] != 0) || ((sym->flags1 & 0x40) != 0)) {
    rec->kind = '\x14';
    return;
  }
  browse_record_set_symbol_with_id(rec,sym);
  bVar4 = sym->kind & 0x1f;
  if (((bVar4 == 0) || (0xe < bVar4)) || (bVar4 == 5)) {
    bVar5 = 0;
  }
  else {
    bVar5 = sym->storage & 7;
    if (bVar5 == 7) {
      rec->attributes = 0;
      rec->sub_kind = '\a';
      goto LAB_1062243b;
    }
  }
  if ((bVar4 == 2) || (bVar4 == 3)) {
    bVar3 = true;
  }
  else {
    bVar3 = false;
  }
  if (bVar5 == 0) {
LAB_1062240a:
    if (1 < g_block_depth) {
      *(byte *)&rec->attributes = (byte)rec->attributes | 1;
    }
  }
  else {
    if (bVar5 < 3) {
      rec->attributes = 0x40;
    }
    else {
      if (bVar5 != 3) goto LAB_1062240a;
      rec->attributes = 2;
    }
    bVar4 = sym->kind & 0x1f;
    if ((bVar4 == 7) || (bVar4 == 8)) {
      if ((~sym->flags1 & 1) != 0) goto LAB_10622479;
    }
    else if ((bVar5 == 1) && ((sym->flags3 & 4) == 0)) {
LAB_10622479:
      *(byte *)&rec->attributes = (byte)rec->attributes | 0x20;
    }
  }
  if (bVar3) {
    *(byte *)&rec->attributes = (byte)rec->attributes | 0x40;
  }
  if ((sym->kind & 0x1f) == 4) {
    pcVar2 = sym->type;
    cVar1 = (char)pcVar2->code;
    while (cVar1 < '\0') {
      pcVar2 = pcVar2->base;
      cVar1 = (char)pcVar2->code;
    }
    uVar6 = pcVar2->code & 0x20f;
    if (uVar6 == 0x201) {
      rec->sub_kind = '\x0f';
    }
    else if (uVar6 == 0x202) {
      rec->sub_kind = '\b';
    }
    else if (uVar6 == 0x203) {
      rec->sub_kind = '\v';
    }
    else if ((pcVar2->code & 0x100) != 0) {
      rec->sub_kind = '\t';
    }
  }
  else {
    rec->sub_kind = g_browse_kind_by_symbol_kind[sym->kind & 0x1f];
  }
LAB_1062243b:
  if (rec->kind != '\x19') {
    return;
  }
  *(byte *)&rec->attributes = (byte)rec->attributes | 0x20;
  rec->kind = '\x03';
  return;
}

