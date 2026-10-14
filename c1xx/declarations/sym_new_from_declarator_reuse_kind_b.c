c1_symbol * __thiscall
sym_new_from_declarator_reuse_kind_b
          (int free_index,void **free_cell,c1_declarator *d,uint mode,void **free_cell_copy,
          void *name)

{
  c1_u8 cVar1;
  c1_u8 cVar2;
  c1_u8 cVar3;
  c1_u32 cVar4;
  byte bVar5;
  c1_symbol *pcVar6;
  uint *copy;
  uint uVar7;
  c1_symbol *pcVar8;
  uint *declspec_rec;
  
  g_symbol_free_lists[free_index] = free_cell[1];
  pcVar6 = (c1_symbol *)(free_cell + -2);
  *free_cell = (void *)0x0;
  free_cell[1] = (void *)0x0;
  cVar4 = g_symbol_size_table[0xb];
  pcVar8 = pcVar6;
  for (uVar7 = g_symbol_size_table[0xb] >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
    *(void **)pcVar8 = (void *)0x0;
    pcVar8 = (c1_symbol *)&pcVar8->flags4;
  }
  for (uVar7 = cVar4 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
    pcVar8->kind = '\0';
    pcVar8 = (c1_symbol *)&pcVar8->flags1;
  }
  *free_cell_copy = name;
  pcVar6->kind = pcVar6->kind & 0xeb | 0xb;
  if (pcVar6 == (c1_symbol *)0x0) {
    pcVar6 = sym_alloc_record(0x38,0xb,mode);
    if (pcVar6 != (c1_symbol *)0x0) {
      pcVar6 = sym_init_kind(pcVar6,'\v',name,mode);
      pcVar6->type = d->type;
      cVar1 = d->spec[1];
      cVar2 = d->spec[2];
      cVar3 = d->spec[3];
      pcVar6->storage = d->spec[0];
      pcVar6->flags21 = cVar1;
      pcVar6->flags22 = cVar2;
      pcVar6->flags23 = cVar3;
      if ((((pcVar6->kind & 0x1f) == 7) || (bVar5 = pcVar6->kind & 0x1f, bVar5 == 8)) ||
         (bVar5 == 6)) {
        *(byte *)((int)&pcVar6->tail + 0xb) =
             d->spec[0x14] >> 3 & 1 ^ *(byte *)((int)&pcVar6->tail + 0xb) & 0xfe;
      }
      if (((d->spec[3] & 1) == 0) || (*(void **)(d->spec + 4) == (void *)0x0)) {
        pcVar6->flags23 = pcVar6->flags23 & 0xfe;
      }
      else {
        sym_set_segment(pcVar6,*(void **)(d->spec + 4));
      }
      if ((d->spec[1] & 0x40) == 0) {
        sym_attach_declspec_record(pcVar6,(uint *)0x0);
      }
      else {
        declspec_rec = *(uint **)(d->spec + 0xc);
        if (declspec_rec == (uint *)0x0) {
          pcVar6->flags21 = pcVar6->flags21 & 0xbf;
        }
        else {
          copy = arena_alloc(g_arenas,0x10);
          if (copy == (uint *)0x0) {
            sym_attach_extra(pcVar6,(void *)0x0);
          }
          else {
            *copy = *declspec_rec;
            copy[1] = declspec_rec[1];
            copy[2] = declspec_rec[2];
            copy[3] = declspec_rec[3];
            sym_attach_extra(pcVar6,copy);
          }
        }
      }
      if (*(void **)(d->spec + 8) == (void *)0x0) {
        pcVar6->flags23 = pcVar6->flags23 & 0x7f;
      }
      else {
        symtab_1b40_insert(pcVar6,*(void **)(d->spec + 8));
      }
      pcVar6->flags2 = (d->flags55 & 4) << 2 | pcVar6->flags2 & 0xef;
      pcVar6->flags3 = d->flags54 >> 5 & 1 | pcVar6->flags3 & 0xfe;
      pcVar6->flags2 = d->flags54 >> 1 & 4 | pcVar6->flags2 & 0xfb;
      pcVar6->flags4 = (pcVar6->flags4 ^ d->flags54) & 4 ^ pcVar6->flags4;
      pcVar6->flags3 = d->flags57 >> 2 & 8 | pcVar6->flags3 & 0xf7;
      pcVar6->flags2 = d->flags54 >> 1 & 8 | pcVar6->flags2 & 0xf7;
      pcVar6->flags1 = (pcVar6->flags1 ^ d->flags54) & 3 ^ pcVar6->flags1;
      if ((pcVar6->entity & 0xffffff) == 0) {
        if (0x7ffffffe < g_next_entity_id) {
          diag_fatal_simple(0x37);
        }
        uVar7 = g_next_entity_id ^ pcVar6->entity;
        g_next_entity_id = g_next_entity_id + 1;
        pcVar6->entity = uVar7 & 0xffffff ^ pcVar6->entity;
      }
      pcVar6->position = d->position;
      return pcVar6;
    }
    pcVar6 = (c1_symbol *)0x0;
  }
  pcVar6->type = d->type;
  pcVar6 = sym_finish_new(pcVar6,d);
  return pcVar6;
}

