c1_symbol * __thiscall sym_new_from_declarator_arena4_block(c1_declarator *d)

{
  fe_name *name;
  c1_u8 cVar1;
  c1_u8 cVar2;
  c1_u8 cVar3;
  byte bVar4;
  c1_symbol *pcVar5;
  uint uVar6;
  uint *copy;
  fe_name *pfStack0000002c;
  uint *declspec_rec;
  
  name = d->name;
  pfStack0000002c = name;
  pcVar5 = sym_alloc_record(0x38,10,4);
  if (pcVar5 == (c1_symbol *)0x0) {
    pcVar5 = (c1_symbol *)0x0;
  }
  else {
    pcVar5 = sym_init_kind(pcVar5,'\n',name,4);
  }
  pcVar5->type = d->type;
  pcVar5->flags5 = d->flags54 >> 5 & 4 | pcVar5->flags5 & 0xfb;
  pcVar5->flags2 = (d->flags55 & 0xfe) << 6 | pcVar5->flags2 & 0x7f;
  pcVar5->flags5 = (pcVar5->flags5 ^ d->flags55) & 1 ^ pcVar5->flags5;
  pcVar5->flags3 = (d->flags56 ^ pcVar5->flags3) & 0x7f ^ d->flags56;
  (pcVar5->tail).data.value_lo = d->unk3c;
  if (d->owner == (c1_symbol *)0x0) {
    cVar1 = d->spec[1];
    cVar2 = d->spec[2];
    cVar3 = d->spec[3];
    pcVar5->storage = d->spec[0];
    pcVar5->flags21 = cVar1;
    pcVar5->flags22 = cVar2;
    pcVar5->flags23 = cVar3;
    if ((((pcVar5->kind & 0x1f) == 7) || (bVar4 = pcVar5->kind & 0x1f, bVar4 == 8)) || (bVar4 == 6))
    {
      *(byte *)((int)&pcVar5->tail + 0xb) =
           d->spec[0x14] >> 3 & 1 ^ *(byte *)((int)&pcVar5->tail + 0xb) & 0xfe;
    }
    if (((d->spec[3] & 1) == 0) || (*(void **)(d->spec + 4) == (void *)0x0)) {
      pcVar5->flags23 = pcVar5->flags23 & 0xfe;
    }
    else {
      sym_set_segment(pcVar5,*(void **)(d->spec + 4));
    }
    if ((d->spec[1] & 0x40) == 0) {
      sym_attach_declspec_record(pcVar5,(uint *)0x0);
    }
    else {
      declspec_rec = *(uint **)(d->spec + 0xc);
      if (declspec_rec == (uint *)0x0) {
        pcVar5->flags21 = pcVar5->flags21 & 0xbf;
      }
      else {
        copy = arena_alloc(g_arenas,0x10);
        if (copy == (uint *)0x0) {
          sym_attach_extra(pcVar5,(void *)0x0);
        }
        else {
          *copy = *declspec_rec;
          copy[1] = declspec_rec[1];
          copy[2] = declspec_rec[2];
          copy[3] = declspec_rec[3];
          sym_attach_extra(pcVar5,copy);
        }
      }
    }
    if (*(void **)(d->spec + 8) == (void *)0x0) {
      pcVar5->flags23 = pcVar5->flags23 & 0x7f;
    }
    else {
      symtab_1b40_insert(pcVar5,*(void **)(d->spec + 8));
    }
    pcVar5->flags2 = (d->flags55 & 4) << 2 | pcVar5->flags2 & 0xef;
    pcVar5->flags3 = d->flags54 >> 5 & 1 | pcVar5->flags3 & 0xfe;
    pcVar5->flags2 = d->flags54 >> 1 & 4 | pcVar5->flags2 & 0xfb;
    pcVar5->flags4 = (pcVar5->flags4 ^ d->flags54) & 4 ^ pcVar5->flags4;
    pcVar5->flags3 = d->flags57 >> 2 & 8 | pcVar5->flags3 & 0xf7;
    pcVar5->flags2 = d->flags54 >> 1 & 8 | pcVar5->flags2 & 0xf7;
    pcVar5->flags1 = (pcVar5->flags1 ^ d->flags54) & 3 ^ pcVar5->flags1;
    if ((pcVar5->entity & 0xffffff) == 0) {
      if (0x7ffffffe < g_next_entity_id) {
        diag_fatal_simple(0x37);
      }
      uVar6 = g_next_entity_id ^ pcVar5->entity;
      g_next_entity_id = g_next_entity_id + 1;
      pcVar5->entity = uVar6 & 0xffffff ^ pcVar5->entity;
    }
    pcVar5->position = d->position;
    return pcVar5;
  }
  pcVar5 = sym_finish_new_with_line(d->owner,pcVar5,pcVar5,d);
  return pcVar5;
}

