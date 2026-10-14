c1_symbol * __thiscall sym_new_from_declarator(c1_declarator *d,uint mode)

{
  byte *pbVar1;
  c1_u8 cVar2;
  fe_name *pfVar3;
  uint *puVar4;
  c1_u8 *pcVar5;
  c1_u8 cVar6;
  c1_u8 cVar7;
  c1_u32 cVar8;
  byte bVar9;
  byte bVar10;
  byte bVar11;
  c1_node *pcVar12;
  c1_type_extra sym;
  c1_type *pcVar13;
  c1_symtab *pcVar14;
  c1_symbol *pcVar15;
  uint *copy;
  byte bVar16;
  c1_arena *pcVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  int unused;
  c1_type_extra cVar21;
  c1_symbol *pcVar22;
  c1_type local_10;
  void **free_cell;
  
  uVar20 = mode;
  if (mode == 0xffffffff) {
    if (((((g_block_depth == '\0') || (-1 < g_class_depth)) ||
         ((g_compile_flags_c8 & 0x10000000) != 0)) ||
        ((((g_compile_flags_c8 & 0x40000000) != 0 && (((byte)g_compile_flags_cc & 8) == 0)) &&
         ((g_compile_flags_c4 & 0x200) == 0)))) || (((byte)g_compile_flags_cc & 0x50) != 0)) {
      uVar20 = 0;
    }
    else {
      uVar20 = 4;
    }
  }
  switch(d->kind) {
  case 1:
  case 2:
    pfVar3 = d->name;
    bVar11 = (d->kind == 2) + 2;
    mode = CONCAT31(mode._1_3_,bVar11);
    if (uVar20 == 0) {
      puVar4 = g_symbol_free_lists[g_symbol_size_class_table[bVar11]];
      if (puVar4 != (uint *)0x0) {
        g_symbol_free_lists[g_symbol_size_class_table[bVar11]] = (uint *)puVar4[1];
        pcVar15 = (c1_symbol *)(puVar4 + -2);
        *puVar4 = 0;
        puVar4[1] = 0;
        uVar19 = g_symbol_size_table[bVar11];
        pcVar22 = pcVar15;
        for (uVar18 = uVar19 >> 2; uVar18 != 0; uVar18 = uVar18 - 1) {
          pcVar22->kind = '\0';
          pcVar22->flags1 = '\0';
          pcVar22->flags2 = '\0';
          pcVar22->flags3 = '\0';
          pcVar22 = (c1_symbol *)&pcVar22->flags4;
        }
        for (uVar19 = uVar19 & 3; uVar19 != 0; uVar19 = uVar19 - 1) {
          pcVar22->kind = '\0';
          pcVar22 = (c1_symbol *)&pcVar22->flags1;
        }
        *puVar4 = (uint)pfVar3;
        pcVar15->kind = (pcVar15->kind ^ bVar11) & 0x1f ^ pcVar15->kind;
        if (pcVar15 != (c1_symbol *)0x0) goto LAB_10403539;
      }
    }
    pcVar15 = sym_alloc_record(0x38,mode,uVar20);
    if (pcVar15 == (c1_symbol *)0x0) {
      pcVar15 = (c1_symbol *)0x0;
    }
    else {
      pcVar15 = sym_init_kind(pcVar15,bVar11,pfVar3,uVar20);
    }
LAB_10403539:
    if (d->kind == 2) {
      pcVar15->flags5 = d->flags54 >> 5 & 4 | pcVar15->flags5 & 0xfb;
      pcVar15->flags2 = (d->flags55 & 0xfe) << 6 | pcVar15->flags2 & 0x7f;
      pcVar15->flags5 = (pcVar15->flags5 ^ d->flags55) & 1 ^ pcVar15->flags5;
    }
    else {
      (pcVar15->x28).bytes.depth = d->depth;
    }
    pcVar15->type = d->type;
    if (d->owner != (c1_symbol *)0x0) {
      pcVar15->scope_index = ((d->owner->detail).cls)->scope_index;
    }
    pcVar15->flags2 =
         (g_class_def_stack[g_class_depth].flags ^ pcVar15->flags2) & 3 ^ pcVar15->flags2;
    pcVar15 = sym_finish_new(pcVar15,d);
    return pcVar15;
  case 3:
    if (((((uVar20 == 0) && (cVar2 = g_current_scope->current->kind, cVar2 != '\0')) &&
         ((d->flags56 & 0x80) == 0)) &&
        ((cVar2 != 0xfa && (((byte)g_compile_flags_cc & 0x20) == 0)))) && (g_block_depth != '\0')) {
      pcVar15 = sym_new_from_declarator_arena4_block(d);
      return pcVar15;
    }
    pfVar3 = d->name;
    if ((uVar20 == 0) &&
       (puVar4 = g_symbol_free_lists[g_symbol_size_class_table[10]], puVar4 != (uint *)0x0)) {
      g_symbol_free_lists[g_symbol_size_class_table[10]] = (uint *)puVar4[1];
      pcVar15 = (c1_symbol *)(puVar4 + -2);
      *puVar4 = 0;
      puVar4[1] = 0;
      cVar8 = g_symbol_size_table[10];
      pcVar22 = pcVar15;
      for (uVar19 = g_symbol_size_table[10] >> 2; uVar19 != 0; uVar19 = uVar19 - 1) {
        pcVar22->kind = '\0';
        pcVar22->flags1 = '\0';
        pcVar22->flags2 = '\0';
        pcVar22->flags3 = '\0';
        pcVar22 = (c1_symbol *)&pcVar22->flags4;
      }
      for (uVar19 = cVar8 & 3; uVar19 != 0; uVar19 = uVar19 - 1) {
        pcVar22->kind = '\0';
        pcVar22 = (c1_symbol *)&pcVar22->flags1;
      }
      *puVar4 = (uint)pfVar3;
      pcVar15->kind = pcVar15->kind & 0xea | 10;
      if (pcVar15 == (c1_symbol *)0x0) goto LAB_104031b4;
    }
    else {
LAB_104031b4:
      pcVar15 = sym_alloc_record(0x38,10,uVar20);
      if (pcVar15 == (c1_symbol *)0x0) {
        pcVar15 = (c1_symbol *)0x0;
      }
      else {
        pcVar15 = sym_init_kind(pcVar15,'\n',pfVar3,uVar20);
      }
    }
    pcVar15->type = d->type;
    pcVar15->flags5 = d->flags54 >> 5 & 4 | pcVar15->flags5 & 0xfb;
    pcVar15->flags2 = (d->flags55 & 0xfe) << 6 | pcVar15->flags2 & 0x7f;
    pcVar15->flags5 = (pcVar15->flags5 ^ d->flags55) & 1 ^ pcVar15->flags5;
    pcVar15->flags3 = (d->flags56 ^ pcVar15->flags3) & 0x7f ^ d->flags56;
    (pcVar15->tail).data.value_lo = d->unk3c;
    if (d->owner != (c1_symbol *)0x0) {
      pcVar15 = sym_finish_new_with_line(d->owner,pcVar15,pcVar15,d);
      return pcVar15;
    }
    goto code_r0x10403654;
  case 4:
    if (((g_compile_flags_c8 & 0x10000000) == 0) && (((byte)g_compile_flags_cc & 0x40) == 0)) {
      if (g_prototype_scope_depth < 1) {
        unused = 5;
      }
      else {
        unused = (g_class_depth < 0) + 3;
      }
    }
    else {
      unused = 0;
    }
    pfVar3 = d->name;
    if ((unused == 0) &&
       (puVar4 = g_symbol_free_lists[g_symbol_size_class_table[0xd]], puVar4 != (uint *)0x0)) {
      pcVar15 = (c1_symbol *)(puVar4 + -2);
      g_symbol_free_lists[g_symbol_size_class_table[0xd]] = (uint *)puVar4[1];
      *puVar4 = 0;
      puVar4[1] = 0;
      cVar8 = g_symbol_size_table[0xd];
      pcVar22 = pcVar15;
      for (uVar20 = g_symbol_size_table[0xd] >> 2; uVar20 != 0; uVar20 = uVar20 - 1) {
        pcVar22->kind = '\0';
        pcVar22->flags1 = '\0';
        pcVar22->flags2 = '\0';
        pcVar22->flags3 = '\0';
        pcVar22 = (c1_symbol *)&pcVar22->flags4;
      }
      for (uVar20 = cVar8 & 3; uVar20 != 0; uVar20 = uVar20 - 1) {
        pcVar22->kind = '\0';
        pcVar22 = (c1_symbol *)&pcVar22->flags1;
      }
      *puVar4 = (uint)pfVar3;
      pcVar15->kind = pcVar15->kind & 0xed | 0xd;
      if (pcVar15 != (c1_symbol *)0x0) goto LAB_10403b2d;
    }
    pcVar17 = g_arenas + unused;
    uVar20 = g_symbol_size_table[0xd] + 3;
    pcVar15 = (c1_symbol *)pcVar17->cur;
    pcVar5 = g_arenas[unused].end;
    pcVar17->cur = &pcVar15->kind + (uVar20 & 0xfffffffc);
    if (pcVar5 < &pcVar15->kind + (uVar20 & 0xfffffffc)) {
      arena_grow(pcVar17);
    }
    if (pcVar15 == (c1_symbol *)0x0) {
      pcVar15 = (c1_symbol *)0x0;
    }
    else {
      pcVar15 = sym_init_kind(pcVar15,'\r',pfVar3,unused);
    }
LAB_10403b2d:
    pcVar15->type = d->type;
    pcVar15->flags5 = d->flags54 >> 5 & 4 | pcVar15->flags5 & 0xfb;
    pcVar15->flags2 = (d->flags55 & 0xfe) << 6 | pcVar15->flags2 & 0x7f;
    pcVar15->flags5 = (pcVar15->flags5 ^ d->flags55) & 1 ^ pcVar15->flags5;
    pcVar15 = sym_finish_new(pcVar15,d);
    return pcVar15;
  case 5:
    if (((uVar20 == 0) && (((byte)g_compile_flags_cc & 0x48) == 0)) &&
       ((g_compile_flags_c8 & 0x10000000) == 0)) {
      if (g_class_depth < 0) {
        if (((byte)g_compile_flags_cc & 1) != 0) {
          uVar20 = 4;
        }
      }
      else {
        uVar20 = 3;
      }
    }
    pfVar3 = d->name;
    if ((uVar20 == 0) &&
       (free_cell = (void **)g_symbol_free_lists[g_symbol_size_class_table[0xb]],
       free_cell != (void **)0x0)) {
      pcVar15 = sym_new_from_declarator_reuse_kind_b
                          (g_symbol_size_class_table[0xb],free_cell,d,0,free_cell,pfVar3);
      return pcVar15;
    }
    pcVar15 = sym_alloc_record(0x38,0xb,uVar20);
    if (pcVar15 != (c1_symbol *)0x0) {
      pcVar15 = sym_init_kind(pcVar15,'\v',pfVar3,uVar20);
      pcVar15->type = d->type;
      goto code_r0x10403654;
    }
    break;
  case 6:
    if (((uVar20 == 0) && (((byte)g_compile_flags_cc & 0x48) == 0)) &&
       ((g_compile_flags_c8 & 0x10000000) == 0)) {
      if (g_class_depth < 0) {
        if (((byte)g_compile_flags_cc & 1) != 0) {
          uVar20 = 4;
        }
      }
      else {
        uVar20 = 3;
      }
    }
    pfVar3 = d->name;
    if ((uVar20 == 0) &&
       (puVar4 = g_symbol_free_lists[g_symbol_size_class_table[0xc]], puVar4 != (uint *)0x0)) {
      g_symbol_free_lists[g_symbol_size_class_table[0xc]] = (uint *)puVar4[1];
      pcVar15 = (c1_symbol *)(puVar4 + -2);
      *puVar4 = 0;
      puVar4[1] = 0;
      cVar8 = g_symbol_size_table[0xc];
      pcVar22 = pcVar15;
      for (uVar19 = g_symbol_size_table[0xc] >> 2; uVar19 != 0; uVar19 = uVar19 - 1) {
        pcVar22->kind = '\0';
        pcVar22->flags1 = '\0';
        pcVar22->flags2 = '\0';
        pcVar22->flags3 = '\0';
        pcVar22 = (c1_symbol *)&pcVar22->flags4;
      }
      for (uVar19 = cVar8 & 3; uVar19 != 0; uVar19 = uVar19 - 1) {
        pcVar22->kind = '\0';
        pcVar22 = (c1_symbol *)&pcVar22->flags1;
      }
      *puVar4 = (uint)pfVar3;
      pcVar15->kind = pcVar15->kind & 0xec | 0xc;
      if (pcVar15 != (c1_symbol *)0x0) goto LAB_10472dca;
    }
    pcVar15 = sym_alloc_record(0x38,0xc,uVar20);
    if (pcVar15 != (c1_symbol *)0x0) {
      pcVar15 = sym_init_kind(pcVar15,'\f',pfVar3,uVar20);
      pcVar15->type = d->type;
      pcVar15 = sym_finish_new(pcVar15,d);
      return pcVar15;
    }
    break;
  case 7:
    pfVar3 = d->name;
    pcVar15 = sym_take_free_record(7,pfVar3,uVar20);
    if (pcVar15 == (c1_symbol *)0x0) {
      pcVar15 = arena_alloc(g_arenas + uVar20,g_symbol_size_table[7] + 3 & 0xfffffffc);
      if (pcVar15 == (c1_symbol *)0x0) {
        pcVar15 = (c1_symbol *)0x0;
      }
      else {
        pcVar15 = sym_init_kind(pcVar15,'\a',pfVar3,uVar20);
      }
    }
    bVar11 = *(byte *)((int)&pcVar15->tail + 8);
    pcVar15->type = d->type;
    *(byte *)((int)&pcVar15->tail + 8) = (d->flags56 & 4) << 1 | bVar11 & 0xf7;
    (pcVar15->tail).fn.op_token = d->op_token;
    *(byte *)((int)&pcVar15->tail + 9) =
         d->flags56 >> 3 & 1 | *(byte *)((int)&pcVar15->tail + 9) & 0xfe;
    (pcVar15->tail).fn.special_kind = d->special_kind;
    if ((d->flags56 & 0x20) != 0) {
      pbVar1 = (byte *)((int)&pcVar15->tail + 9);
      *pbVar1 = *pbVar1 | 0x40;
    }
    if ((d->flags57 & 1) != 0) {
      pbVar1 = (byte *)((int)&pcVar15->tail + 9);
      *pbVar1 = *pbVar1 | 0x80;
    }
    if (((byte)g_compile_flags_cc & 0x20) != 0) {
      pbVar1 = (byte *)((int)&pcVar15->tail + 9);
      *pbVar1 = *pbVar1 | 0x20;
    }
    pcVar22 = d->owner;
    if (pcVar22 != (c1_symbol *)0x0) {
      if ((pcVar22->kind & 0x1f) == 0x19) {
        pcVar15->scope_index = *(c1_u16 *)&pcVar22->type->base;
      }
      else if (pcVar22 != (c1_symbol *)0x0) {
        sym_inherit_scope_index(pcVar15,&pcVar22->kind);
      }
    }
    if (d->specialized_template != (c1_symbol *)0x0) {
      pcVar15 = sym_finish_new_member_fragment(d->specialized_template,pcVar15,d);
      return pcVar15;
    }
    goto LAB_104034bc;
  case 8:
    pfVar3 = d->name;
    pcVar15 = sym_take_free_record(8,pfVar3,uVar20);
    if (pcVar15 == (c1_symbol *)0x0) {
      pcVar15 = arena_alloc(g_arenas + uVar20,g_symbol_size_table[8] + 3 & 0xfffffffc);
      if (pcVar15 == (c1_symbol *)0x0) {
        pcVar15 = (c1_symbol *)0x0;
      }
      else {
        pcVar15 = sym_init_kind(pcVar15,'\b',pfVar3,uVar20);
      }
    }
    pcVar15->type = d->type;
    pcVar15->flags1 = (d->flags56 & 1) << 6 | pcVar15->flags1 & 0xbf;
    *(byte *)((int)&pcVar15->tail + 8) =
         (d->flags56 & 4) << 1 | *(byte *)((int)&pcVar15->tail + 8) & 0xf7;
    bVar10 = d->flags56 >> 3 & 1 | *(byte *)((int)&pcVar15->tail + 9) & 0xfe;
    bVar11 = *(byte *)((int)&pcVar15->tail + 8);
    *(byte *)((int)&pcVar15->tail + 9) = bVar10;
    (pcVar15->tail).fn.op_token = d->op_token;
    *(byte *)((int)&pcVar15->tail + 9) = (d->flags57 ^ bVar10) & 0x10 ^ bVar10;
    bVar10 = (d->flags57 & 2) << 3;
    *(byte *)((int)&pcVar15->tail + 8) = bVar10 | bVar11 & 0xef;
    bVar16 = (d->flags57 & 4) << 3;
    *(byte *)((int)&pcVar15->tail + 8) = bVar16 | bVar10 | bVar11 & 0xcf;
    bVar9 = (d->flags57 & 0xf8) << 4;
    *(byte *)((int)&pcVar15->tail + 8) = bVar9 | bVar16 | bVar10 | bVar11 & 0x4f;
    *(byte *)((int)&pcVar15->tail + 8) =
         d->flags56 >> 4 & 1 | bVar9 | bVar16 | bVar10 | bVar11 & 0x4e;
    (pcVar15->tail).fn.special_kind = d->special_kind;
    pcVar15->scope_index = ((d->owner->detail).cls)->scope_index;
    pcVar15->flags2 =
         (g_class_def_stack[g_class_depth].flags ^ pcVar15->flags2) & 3 ^ pcVar15->flags2;
    if ((d->flags55 & 0x40) != 0) {
      pcVar15->flags1 = pcVar15->flags1 | 0x10;
    }
    if ((d->flags55 & 0x80) != 0) {
      pcVar15->flags1 = pcVar15->flags1 | 0x20;
    }
    if ((d->flags56 & 0x20) != 0) {
      pbVar1 = (byte *)((int)&pcVar15->tail + 9);
      *pbVar1 = *pbVar1 | 0x40;
    }
    if ((d->flags57 & 1) != 0) {
      pbVar1 = (byte *)((int)&pcVar15->tail + 9);
      *pbVar1 = *pbVar1 | 0x80;
    }
    if (((byte)g_compile_flags_cc & 0x20) != 0) {
      pbVar1 = (byte *)((int)&pcVar15->tail + 9);
      *pbVar1 = *pbVar1 | 0x20;
    }
    if (d->specialized_template != (c1_symbol *)0x0) {
      symtab_1604_insert(pcVar15,d->specialized_template);
    }
LAB_104034bc:
    if (d->template_args != (c1_arg_list *)0x0) {
      pcVar15 = sym_finish_new_static_member_fragment(d->template_args,pcVar15,d);
      return pcVar15;
    }
code_r0x10403654:
    cVar2 = d->spec[1];
    cVar6 = d->spec[2];
    cVar7 = d->spec[3];
    pcVar15->storage = d->spec[0];
    pcVar15->flags21 = cVar2;
    pcVar15->flags22 = cVar6;
    pcVar15->flags23 = cVar7;
    if ((((pcVar15->kind & 0x1f) == 7) || (bVar11 = pcVar15->kind & 0x1f, bVar11 == 8)) ||
       (bVar11 == 6)) {
      *(byte *)((int)&pcVar15->tail + 0xb) =
           d->spec[0x14] >> 3 & 1 ^ *(byte *)((int)&pcVar15->tail + 0xb) & 0xfe;
    }
    if (((d->spec[3] & 1) == 0) || (*(void **)(d->spec + 4) == (void *)0x0)) {
      pcVar15->flags23 = pcVar15->flags23 & 0xfe;
    }
    else {
      sym_set_segment(pcVar15,*(void **)(d->spec + 4));
    }
    if ((d->spec[1] & 0x40) == 0) {
      sym_attach_declspec_record(pcVar15,(uint *)0x0);
    }
    else {
      puVar4 = *(uint **)(d->spec + 0xc);
      if (puVar4 == (uint *)0x0) {
        pcVar15->flags21 = pcVar15->flags21 & 0xbf;
      }
      else {
        copy = arena_alloc(g_arenas,0x10);
        if (copy == (uint *)0x0) {
          sym_attach_extra(pcVar15,(void *)0x0);
        }
        else {
          *copy = *puVar4;
          copy[1] = puVar4[1];
          copy[2] = puVar4[2];
          copy[3] = puVar4[3];
          sym_attach_extra(pcVar15,copy);
        }
      }
    }
    if (*(void **)(d->spec + 8) == (void *)0x0) {
      pcVar15->flags23 = pcVar15->flags23 & 0x7f;
    }
    else {
      symtab_1b40_insert(pcVar15,*(void **)(d->spec + 8));
    }
    pcVar15->flags2 = (d->flags55 & 4) << 2 | pcVar15->flags2 & 0xef;
    pcVar15->flags3 = d->flags54 >> 5 & 1 | pcVar15->flags3 & 0xfe;
    pcVar15->flags2 = d->flags54 >> 1 & 4 | pcVar15->flags2 & 0xfb;
    pcVar15->flags4 = (pcVar15->flags4 ^ d->flags54) & 4 ^ pcVar15->flags4;
    pcVar15->flags3 = d->flags57 >> 2 & 8 | pcVar15->flags3 & 0xf7;
    pcVar15->flags2 = d->flags54 >> 1 & 8 | pcVar15->flags2 & 0xf7;
    pcVar15->flags1 = (pcVar15->flags1 ^ d->flags54) & 3 ^ pcVar15->flags1;
    if ((pcVar15->entity & 0xffffff) == 0) {
      if (0x7ffffffe < g_next_entity_id) {
        diag_fatal_simple(0x37);
      }
      uVar20 = g_next_entity_id ^ pcVar15->entity;
      g_next_entity_id = g_next_entity_id + 1;
      pcVar15->entity = uVar20 & 0xffffff ^ pcVar15->entity;
    }
    pcVar15->position = d->position;
    return pcVar15;
  case 9:
    pfVar3 = d->name;
    if ((uVar20 == 0) &&
       (puVar4 = g_symbol_free_lists[g_symbol_size_class_table[5]], puVar4 != (uint *)0x0)) {
      g_symbol_free_lists[g_symbol_size_class_table[5]] = (uint *)puVar4[1];
      pcVar15 = (c1_symbol *)(puVar4 + -2);
      *puVar4 = 0;
      puVar4[1] = 0;
      cVar8 = g_symbol_size_table[5];
      pcVar22 = pcVar15;
      for (uVar19 = g_symbol_size_table[5] >> 2; uVar19 != 0; uVar19 = uVar19 - 1) {
        pcVar22->kind = '\0';
        pcVar22->flags1 = '\0';
        pcVar22->flags2 = '\0';
        pcVar22->flags3 = '\0';
        pcVar22 = (c1_symbol *)&pcVar22->flags4;
      }
      for (uVar19 = cVar8 & 3; uVar19 != 0; uVar19 = uVar19 - 1) {
        pcVar22->kind = '\0';
        pcVar22 = (c1_symbol *)&pcVar22->flags1;
      }
      *puVar4 = (uint)pfVar3;
      pcVar15->kind = pcVar15->kind & 0xe5 | 5;
      if (pcVar15 == (c1_symbol *)0x0) goto LAB_104038a1;
    }
    else {
LAB_104038a1:
      pcVar15 = sym_alloc_record(0x38,5,uVar20);
      if (pcVar15 == (c1_symbol *)0x0) {
        pcVar15 = (c1_symbol *)0x0;
      }
      else {
        pcVar15 = sym_init_kind(pcVar15,'\x05',pfVar3,uVar20);
      }
    }
    pcVar15->type = d->type;
    if (-1 < g_class_depth) {
      pcVar15->flags2 =
           (g_class_def_stack[g_class_depth].flags ^ pcVar15->flags2) & 3 ^ pcVar15->flags2;
      pcVar15 = sym_finish_new(pcVar15,d);
      return pcVar15;
    }
    goto code_r0x10403654;
  default:
    pfVar3 = d->name;
    if ((uVar20 == 0) &&
       (puVar4 = g_symbol_free_lists[g_symbol_size_class_table[1]], puVar4 != (uint *)0x0)) {
      g_symbol_free_lists[g_symbol_size_class_table[1]] = (uint *)puVar4[1];
      pcVar15 = (c1_symbol *)(puVar4 + -2);
      *puVar4 = 0;
      puVar4[1] = 0;
      cVar8 = g_symbol_size_table[1];
      pcVar22 = pcVar15;
      for (uVar19 = g_symbol_size_table[1] >> 2; uVar19 != 0; uVar19 = uVar19 - 1) {
        pcVar22->kind = '\0';
        pcVar22->flags1 = '\0';
        pcVar22->flags2 = '\0';
        pcVar22->flags3 = '\0';
        pcVar22 = (c1_symbol *)&pcVar22->flags4;
      }
      for (uVar19 = cVar8 & 3; uVar19 != 0; uVar19 = uVar19 - 1) {
        pcVar22->kind = '\0';
        pcVar22 = (c1_symbol *)&pcVar22->flags1;
      }
      *puVar4 = (uint)pfVar3;
      pcVar15->kind = pcVar15->kind & 0xe1 | 1;
      if (pcVar15 != (c1_symbol *)0x0) goto LAB_104730f7;
    }
    pcVar17 = g_arenas + uVar20;
    uVar19 = g_symbol_size_table[1] + 3;
    pcVar15 = (c1_symbol *)pcVar17->cur;
    pcVar5 = g_arenas[uVar20].end;
    pcVar17->cur = &pcVar15->kind + (uVar19 & 0xfffffffc);
    if (pcVar5 < &pcVar15->kind + (uVar19 & 0xfffffffc)) {
      arena_grow(pcVar17);
    }
    if (pcVar15 == (c1_symbol *)0x0) {
      pcVar15 = (c1_symbol *)0x0;
    }
    else {
      pcVar15 = sym_init_kind(pcVar15,'\x01',pfVar3,uVar20);
    }
LAB_104730f7:
    pcVar15->type = d->type;
    pcVar15 = sym_finish_new(pcVar15,d);
    return pcVar15;
  case 0xb:
    pfVar3 = d->name;
    puVar4 = g_symbol_free_lists[g_symbol_size_class_table[0x17]];
    if (puVar4 == (uint *)0x0) {
LAB_104037d8:
      pcVar15 = sym_alloc_record(0x38,0x17,0);
      if (pcVar15 == (c1_symbol *)0x0) {
        pcVar15 = (c1_symbol *)0x0;
      }
      else {
        pcVar15 = sym_init_kind(pcVar15,'\x17',pfVar3,0);
      }
    }
    else {
      pcVar15 = (c1_symbol *)(puVar4 + -2);
      g_symbol_free_lists[g_symbol_size_class_table[0x17]] = (uint *)puVar4[1];
      *puVar4 = 0;
      puVar4[1] = 0;
      cVar8 = g_symbol_size_table[0x17];
      pcVar22 = pcVar15;
      for (uVar20 = g_symbol_size_table[0x17] >> 2; uVar20 != 0; uVar20 = uVar20 - 1) {
        pcVar22->kind = '\0';
        pcVar22->flags1 = '\0';
        pcVar22->flags2 = '\0';
        pcVar22->flags3 = '\0';
        pcVar22 = (c1_symbol *)&pcVar22->flags4;
      }
      for (uVar20 = cVar8 & 3; uVar20 != 0; uVar20 = uVar20 - 1) {
        pcVar22->kind = '\0';
        pcVar22 = (c1_symbol *)&pcVar22->flags1;
      }
      *puVar4 = (uint)pfVar3;
      pcVar15->kind = pcVar15->kind & 0xf7 | 0x17;
      if (pcVar15 == (c1_symbol *)0x0) goto LAB_104037d8;
    }
    pcVar13 = d->type;
    bVar11 = (byte)pcVar13->code;
    if ((bVar11 & 0x8f) == 0x83) {
      pcVar13 = type_reference_to(pcVar13,'\0');
      pcVar15->type = pcVar13;
    }
    else if ((bVar11 & 0x83) == 0x81) {
      pcVar13 = type_member_pointer_to_2(pcVar13,'\0');
      pcVar15->type = pcVar13;
    }
    else {
      pcVar15->type = pcVar13;
    }
    pcVar15->flags5 = pcVar15->flags5 | 0x40;
    g_template_parameter_index = g_template_parameter_index + 1;
    pcVar12 = tree_new_int_constant
                        ((int)(short)((ushort)g_template_parameter_index |
                                     (ushort)(byte)g_template_depth << 8));
    pcVar12 = tree_copy_to_arena(pcVar12,0);
    pcVar12->flags = pcVar12->flags | 8;
    (pcVar15->tail).tparam_value = pcVar12;
    bVar11 = (byte)d->type->code;
    if (((char)bVar11 < '\0') && ((bVar11 & 0x8f) == 0x80)) {
      pcVar15 = tmpl_check_reference_parameter(pcVar15,d);
      return pcVar15;
    }
    goto code_r0x10403654;
  case 0xd:
    pfVar3 = d->name;
    puVar4 = g_symbol_free_lists[g_symbol_size_class_table[4]];
    if (puVar4 == (uint *)0x0) {
LAB_1040390c:
      pcVar15 = sym_alloc_record(0x38,4,0);
      if (pcVar15 == (c1_symbol *)0x0) {
        sym.cls = (c1_symbol *)0x0;
      }
      else {
        sym.cls = sym_init_kind(pcVar15,'\x04',pfVar3,0);
      }
    }
    else {
      g_symbol_free_lists[g_symbol_size_class_table[4]] = (uint *)puVar4[1];
      *puVar4 = 0;
      sym.cls = (c1_symbol *)(puVar4 + -2);
      puVar4[1] = 0;
      cVar8 = g_symbol_size_table[4];
      cVar21.cls = sym.cls;
      for (uVar20 = g_symbol_size_table[4] >> 2; uVar20 != 0; uVar20 = uVar20 - 1) {
        (cVar21.params)->this_type = (c1_type *)0x0;
        cVar21 = (c1_type_extra)&(cVar21.cls)->flags4;
      }
      for (uVar20 = cVar8 & 3; uVar20 != 0; uVar20 = uVar20 - 1) {
        (cVar21.cls)->kind = '\0';
        cVar21 = (c1_type_extra)&(cVar21.cls)->flags1;
      }
      *puVar4 = (uint)pfVar3;
      (sym.cls)->kind = (sym.cls)->kind & 0xe4 | 4;
      if (sym.cls == (c1_symbol *)0x0) goto LAB_1040390c;
    }
    local_10.code = d->unk50;
    local_10.base = (c1_type *)0x0;
    local_10.debug_index = 0;
    local_10.flags = 0;
    local_10.extra = sym;
    pcVar13 = type_intern(&local_10);
    (sym.cls)->type = pcVar13;
    if ((d->unk50 & 0x100) != 0) {
      pcVar14 = symtab_new(4,(g_compile_flags_c4 >> 0x11 & 1) << 2,0,0,'\x01','\x01');
      ((sym.cls)->x28).enumerators = pcVar14;
    }
    pcVar5 = g_arenas[0].cur;
    g_arenas[0].cur = g_arenas[0].cur + 0x48;
    if (g_arenas[0].end < g_arenas[0].cur) {
      arena_grow(g_arenas);
    }
    ((sym.cls)->detail).cls = (c1_class_record *)pcVar5;
    pcVar15 = d->owner;
    if (pcVar15 != (c1_symbol *)0x0) {
      bVar11 = pcVar15->kind & 0x1f;
      if (bVar11 == 4) {
        (sym.cls)->scope_index = ((pcVar15->detail).cls)->scope_index;
        (sym.cls)->flags2 =
             (g_class_def_stack[g_class_depth].flags ^ (sym.cls)->flags2) & 3 ^ (sym.cls)->flags2;
        pcVar5[0x3b] = pcVar5[0x3b] | 2;
        goto LAB_10403995;
      }
      if (bVar11 != 0x19) {
        if ((pcVar15->x28).block_number == 0) {
          scope_vector_add(pcVar15,'\a');
        }
        (sym.cls)->scope_index = (pcVar15->x28).block_number;
        if (((sym.cls)->kind & 0x1f) == 4) {
          (((sym.cls)->detail).cls)->unk38 = g_block_number;
        }
        (sym.cls)->flags2 = (sym.cls)->flags2 | 3;
        (((sym.cls)->detail).cls)->flags3e =
             ~(byte)(g_compile_flags_c4 >> 5) << 7 | (((sym.cls)->detail).cls)->flags3e & 0x7f;
        goto LAB_10403995;
      }
      (sym.cls)->scope_index = *(c1_u16 *)&pcVar15->type->base;
    }
    (sym.cls)->flags2 = (sym.cls)->flags2 | 3;
LAB_10403995:
    bVar11 = (sym.cls)->flags2;
    bVar10 = (d->flags55 & 4) << 2;
    (sym.cls)->flags2 = bVar10 | bVar11 & 0xef;
    (sym.cls)->flags2 = d->flags54 >> 1 & 4 | bVar10 | bVar11 & 0xeb;
    (sym.cls)->flags3 = d->flags54 >> 5 & 1 | (sym.cls)->flags3 & 0xfe;
    (sym.cls)->flags2 = d->flags54 >> 1 & 8 | (sym.cls)->flags2 & 0xf7;
    if ((d->flags56 & 0x40) != 0) {
      pcVar5 = &(((sym.cls)->detail).cls)->flags3e;
      *pcVar5 = *pcVar5 | 2;
    }
    scope_vector_add(sym.cls,'\x04');
    if (g_next_entity_id < 0x7fffffff) {
      uVar20 = g_next_entity_id ^ (sym.cls)->entity;
      g_next_entity_id = g_next_entity_id + 1;
      (sym.cls)->entity = uVar20 & 0xffffff ^ (sym.cls)->entity;
      (sym.cls)->position = d->position;
      return sym.cls;
    }
    diag_fatal_simple(0x37);
  }
  pcVar15 = (c1_symbol *)0x0;
LAB_10472dca:
  pcVar15->type = d->type;
  pcVar15 = sym_finish_new(pcVar15,d);
  return pcVar15;
}

