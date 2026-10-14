c1_symbol * __thiscall sym_new_from_declarator(c1_declaration *decl,int arena)

{
  void *pvVar1;
  uint *puVar2;
  c1_u8 cVar3;
  c1_u8 cVar4;
  c1_u8 cVar5;
  byte bVar6;
  c1_type *pcVar7;
  fe_symtab *pfVar8;
  c1_symbol *sym;
  c1_symbol *pcVar9;
  byte bVar10;
  byte bVar11;
  int arena_00;
  uint uVar12;
  uint uVar13;
  c1_symbol *cursor;
  c1_type local_10;
  
  if (arena == -1) {
    arena = -(uint)(g_block_depth != '\0') & 2;
  }
  switch(decl->context) {
  case 1:
  case 2:
    pvVar1 = decl->name;
    bVar6 = (decl->context == 2) + 2;
    sym = sym_take_free_record(bVar6,pvVar1,arena);
    if (sym == (c1_symbol *)0x0) {
      pcVar9 = arena_alloc(g_arenas + arena,g_symbol_size_table[bVar6] + 3 & 0xfffffffc);
      if (pcVar9 == (c1_symbol *)0x0) {
        sym = (c1_symbol *)0x0;
      }
      else {
        sym = sym_init_kind(pcVar9,bVar6,pvVar1,arena);
      }
    }
    if (decl->context == 2) {
      sym->flags4 = decl->flags2c >> 5 & 4 | sym->flags4 & 0xfb;
      sym->flags1 = (decl->flags2d & 2) << 4 | sym->flags1 & 0xdf;
      sym->flags4 = (decl->flags2d ^ sym->flags4) & 1 ^ sym->flags4;
    }
    else {
      (sym->x28).bytes.depth = decl->width;
    }
    break;
  case 3:
    pvVar1 = decl->name;
    sym = sym_take_free_record(10,pvVar1,arena);
    if (sym == (c1_symbol *)0x0) {
      pcVar9 = arena_alloc(g_arenas + arena,g_symbol_size_table[10] + 3 & 0xfffffffc);
      if (pcVar9 == (c1_symbol *)0x0) goto LAB_10634be0;
      sym = sym_init_kind(pcVar9,'\n',pvVar1,arena);
    }
    goto LAB_10606ccf;
  case 4:
    pvVar1 = decl->name;
    arena_00 = (g_prototype_scope_depth < 1) + 2;
    if ((arena_00 == 0) &&
       (puVar2 = g_symbol_free_lists[g_symbol_size_class_table[0xd]], puVar2 != (uint *)0x0)) {
      g_symbol_free_lists[g_symbol_size_class_table[0xd]] = (uint *)puVar2[1];
      *puVar2 = 0;
      sym = (c1_symbol *)(puVar2 + -2);
      puVar2[1] = 0;
      uVar13 = g_symbol_size_table[0xd];
      cursor = sym;
      for (uVar12 = g_symbol_size_table[0xd] >> 2; uVar12 != 0; uVar12 = uVar12 - 1) {
        ((c1_param_list *)cursor)->count = 0;
        cursor = (c1_symbol *)&cursor->flags4;
      }
      for (uVar13 = uVar13 & 3; uVar13 != 0; uVar13 = uVar13 - 1) {
        cursor->kind = '\0';
        cursor = (c1_symbol *)&cursor->flags1;
      }
      *puVar2 = (uint)pvVar1;
      sym->kind = sym->kind & 0xed | 0xd;
      if (sym != (c1_symbol *)0x0) goto LAB_10606ccf;
    }
    pcVar9 = sym_alloc_record(0x38,0xd,arena_00);
    if (pcVar9 == (c1_symbol *)0x0) {
LAB_10634be0:
      sym = (c1_symbol *)0x0;
    }
    else {
      sym = sym_init_kind(pcVar9,'\r',pvVar1,arena_00);
    }
LAB_10606ccf:
    sym->type = decl->type;
    sym->flags4 = decl->flags2c >> 5 & 4 | sym->flags4 & 0xfb;
    sym->flags1 = (decl->flags2d & 2) << 4 | sym->flags1 & 0xdf;
    sym->flags4 = (decl->flags2d ^ sym->flags4) & 1 ^ sym->flags4;
    goto LAB_10606ee1;
  case 5:
    pvVar1 = decl->name;
    sym = sym_take_free_record(0xb,pvVar1,arena);
    if (sym == (c1_symbol *)0x0) {
      pcVar9 = arena_alloc(g_arenas + arena,g_symbol_size_table[0xb] + 3 & 0xfffffffc);
      if (pcVar9 != (c1_symbol *)0x0) {
        pcVar9 = sym_init_kind(pcVar9,'\v',pvVar1,arena);
        pcVar9 = sym_new_numbered(pcVar9,decl);
        return pcVar9;
      }
LAB_10634be7:
      pcVar9 = sym_new_numbered((c1_symbol *)0x0,decl);
      return pcVar9;
    }
    break;
  case 6:
    pvVar1 = decl->name;
    sym = sym_take_free_record(0xc,pvVar1,arena);
    if (sym == (c1_symbol *)0x0) {
      pcVar9 = arena_alloc(g_arenas + arena,g_symbol_size_table[0xc] + 3 & 0xfffffffc);
      if (pcVar9 != (c1_symbol *)0x0) {
        pcVar9 = sym_init_kind(pcVar9,'\f',pvVar1,arena);
        pcVar9 = sym_new_numbered(pcVar9,decl);
        return pcVar9;
      }
      goto LAB_10634be7;
    }
    break;
  case 7:
    pvVar1 = decl->name;
    sym = sym_take_free_record(7,pvVar1,arena);
    if (sym == (c1_symbol *)0x0) {
      pcVar9 = arena_alloc(g_arenas + arena,g_symbol_size_table[7] + 3 & 0xfffffffc);
      if (pcVar9 != (c1_symbol *)0x0) {
        pcVar9 = sym_init_kind(pcVar9,'\a',pvVar1,arena);
        pcVar9 = sym_new_numbered(pcVar9,decl);
        return pcVar9;
      }
      goto LAB_10634be7;
    }
    break;
  default:
    pvVar1 = decl->name;
    sym = sym_take_free_record(1,pvVar1,arena);
    if (sym == (c1_symbol *)0x0) {
      pcVar9 = arena_alloc(g_arenas + arena,g_symbol_size_table[1] + 3 & 0xfffffffc);
      if (pcVar9 != (c1_symbol *)0x0) {
        pcVar9 = sym_init_kind(pcVar9,'\x01',pvVar1,arena);
        pcVar9 = sym_new_numbered(pcVar9,decl);
        return pcVar9;
      }
      goto LAB_10634be7;
    }
    break;
  case 9:
    pvVar1 = decl->name;
    sym = sym_take_free_record(5,pvVar1,arena);
    if (sym == (c1_symbol *)0x0) {
      pcVar9 = arena_alloc(g_arenas + arena,g_symbol_size_table[5] + 3 & 0xfffffffc);
      if (pcVar9 == (c1_symbol *)0x0) goto LAB_10634be7;
      sym = sym_init_kind(pcVar9,'\x05',pvVar1,arena);
    }
    break;
  case 0xd:
    pvVar1 = decl->name;
    sym = sym_take_free_record(4,pvVar1,0);
    if (sym == (c1_symbol *)0x0) {
      pcVar9 = arena_alloc(g_arenas,g_symbol_size_table[4] + 3 & 0xfffffffc);
      if (pcVar9 == (c1_symbol *)0x0) {
        sym = (c1_symbol *)0x0;
      }
      else {
        sym = sym_init_kind(pcVar9,'\x04',pvVar1,0);
      }
    }
    local_10.code = decl->tag_kind;
    local_10.base = (c1_type *)0x0;
    local_10.debug_index = 0;
    local_10.flags = 0;
    local_10.extra.sym = sym;
    pcVar7 = type_intern(&local_10);
    sym->type = pcVar7;
    if ((decl->tag_kind & 0x100) != 0) {
      pfVar8 = symtab_new(4,(g_compile_flags_c4 >> 0x11 & 1) << 1,0,0,'\x01','\x01');
      sym->tag_members = pfVar8;
    }
    sym->tag_alignment = (ushort)(-1 < g_class_depth) << 9 | sym->tag_alignment & 0xfdff;
    bVar6 = (decl->flags2d ^ sym->flags1) & 4 ^ sym->flags1;
    sym->flags1 = bVar6;
    bVar11 = decl->flags2c >> 3 & 1;
    sym->flags1 = bVar11 | bVar6 & 0xfe;
    bVar10 = (decl->flags2c & 0x20) << 1;
    sym->flags1 = bVar10 | bVar11 | bVar6 & 0xbe;
    sym->flags1 = decl->flags2c >> 3 & 2 | bVar10 | bVar11 | bVar6 & 0xbc;
    goto joined_r0x106070ab;
  }
  sym->type = decl->type;
LAB_10606ee1:
  cVar3 = (decl->spec).inlining;
  cVar4 = (decl->spec).declspec;
  cVar5 = (decl->spec).allocate;
  *(c1_u8 *)((int)sym + 0x20) = (decl->spec).storage;
  *(c1_u8 *)((int)sym + 0x21) = cVar3;
  *(c1_u8 *)((int)sym + 0x22) = cVar4;
  *(c1_u8 *)((int)sym + 0x23) = cVar5;
  if ((((sym->kind & 0x1f) == 7) || (bVar6 = sym->kind & 0x1f, bVar6 == 8)) || (bVar6 == 6)) {
    (sym->x2c).function_flags = (decl->spec).flags8 >> 1 & 1 ^ (sym->x2c).function_flags & 0xfe;
  }
  if (((decl->spec).allocate & 1) == 0) {
    sym_set_or_clear_segment_2(sym,(void *)0x0);
  }
  else {
    pvVar1 = (decl->spec).segment;
    if (pvVar1 == (void *)0x0) {
      sym->flags23 = sym->flags23 & 0xfe;
    }
    else {
      sym_set_segment(sym,pvVar1);
    }
  }
  bVar6 = (decl->flags2d ^ sym->flags1) & 4 ^ sym->flags1;
  sym->flags1 = bVar6;
  bVar10 = (decl->flags2c & 0x20) << 1;
  sym->flags1 = bVar10 | bVar6 & 0xbf;
  sym->flags1 = decl->flags2c >> 3 & 1 | bVar10 | bVar6 & 0xbe;
  sym->flags3 = (sym->flags3 ^ decl->flags2c) & 4 ^ sym->flags3;
  sym->flags2 = decl->flags2f >> 4 & 2 | sym->flags2 & 0xfd;
  sym->flags1 = decl->flags2c >> 3 & 2 | sym->flags1 & 0xfd;
  if ((sym->entity & 0xffffff) == 0) {
joined_r0x106070ab:
    if (0x7ffffffe < g_next_entity_id) {
      diag_fatal_simple(0x37);
    }
    uVar13 = sym->entity ^ g_next_entity_id;
    g_next_entity_id = g_next_entity_id + 1;
    sym->entity = uVar13 & 0xffffff ^ sym->entity;
  }
  sym->position = decl->position;
  return sym;
}

