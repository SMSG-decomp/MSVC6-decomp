void __fastcall conv_rule_conversion_function(c1_conversion *conv)

{
  c1_u8 cVar1;
  c1_symbol *cls;
  c1_type *pcVar2;
  bool bVar3;
  c1_sym_link *pcVar4;
  char cVar5;
  byte bVar6;
  c1_type *pcVar7;
  c1_symbol *sym;
  int iVar8;
  c1_symbol *pcVar9;
  c1_conversion_via cVar10;
  fe_name **ppfVar11;
  c1_conversion *conv_00;
  c1_conversion *local_34;
  c1_sym_link *next_link;
  c1_conversion_type_iter types;
  
  if (((conv->mode == '\a') || (conv->mode == '\b')) || ((conv->flags & 0x20) != 0)) {
    conv->rank = 0x70;
    conv->note_fn = (void *)0x0;
    conv->note = (-(uint)((conv->flags & 0x20) != 0) & 2) + 0x1796;
    return;
  }
  cls = (conv->source->extra).cls;
  if (((cls->flags2 & 4) == 0) && (tmpl_instantiate_if_needed(cls), (cls->flags2 & 4) == 0)) {
    conv->rank = 0x70;
    conv->note = 0x179c;
    conv->note_fn = (void *)0x0;
    return;
  }
  bVar3 = false;
  pcVar7 = type_pointer_with_qualifiers(conv->source,0);
  class_conversion_functions_begin(&types,cls);
  cVar5 = ovl_conversion_types_next(&types);
  local_34 = (c1_conversion *)g_arenas[5].cur;
  do {
    g_arenas[5].cur = &local_34->op;
    if (cVar5 == '\0') {
      bVar6 = conv->flags4f & 2;
      if (bVar6 == 0) {
        if (bVar3) {
          conv->rank = 0x30;
          conv->build = conv_build_conversion_function_call;
          conv->note_fn = diag_note_conversion_call;
          return;
        }
        if ((conv->via).function != (c1_symbol *)0x0) {
          return;
        }
      }
      conv->rank = 0x70;
      if (bVar6 != 0) {
        conv->note = 0x179a;
        conv->note_fn = (void *)0x0;
        return;
      }
      conv->note = 0x1799;
      return;
    }
    if (((conv->flags & 0x40) == 0) ||
       ((bVar6 = (byte)(types.type)->code, (char)bVar6 < '\0' && ((bVar6 & 0x8f) == 0x80)))) {
      g_arenas[5].cur = &local_34[1].op;
      if (g_arenas[5].end < g_arenas[5].cur) {
        arena_grow(g_arenas + 5);
      }
      cVar5 = '\0';
      if (local_34 == (c1_conversion *)0x0) {
        local_34 = (c1_conversion *)0x0;
      }
      else {
        if ((conv->mode == '\x02') || (conv->mode == '\x03')) {
          cVar5 = '\x01';
        }
        bVar6 = conv->flags;
        cVar1 = conv->op;
        local_34->target = conv->target;
        local_34->op = cVar1;
        local_34->mode = cVar5 + '\x01';
        local_34->flags = bVar6 | 0x28;
        local_34->expr = (c1_node *)0x0;
        local_34->source = types.type;
        conv_compute_conversion(local_34);
      }
      if ((local_34->flags4e & 1) != 0) {
        next_link = (c1_sym_link *)0x0;
        sym = class_find_conversion_function(types.type,cls);
        ppfVar11 = &sym->name;
        if (((ppfVar11 != (fe_name **)0x0) &&
            (iVar8 = sym_is_data_or_function_2(sym), next_link = (c1_sym_link *)ppfVar11,
            (char)iVar8 == '\0')) && ((sym->kind & 0x1f) != 0x1a)) {
          next_link = (c1_sym_link *)sym->type;
        }
LAB_10417257:
        while ((pcVar4 = next_link, ppfVar11 != (fe_name **)0x0 && (next_link != (c1_sym_link *)0x0)
               )) {
          iVar8 = sym_is_data_or_function_2(sym);
          conv_00 = (c1_conversion *)g_arenas[5].cur;
          if (((char)iVar8 == '\0') && ((sym->kind & 0x1f) != 0x1a)) {
            next_link = next_link->next;
          }
          else {
            next_link = (c1_sym_link *)0x0;
          }
          cVar10.function = (c1_symbol *)&pcVar4[-1].position;
          bVar6 = (byte)pcVar4[-1].position & 0x1f;
          if (bVar6 == 0x1a) goto LAB_10497901;
          if (((byte)~*(byte *)((int)&pcVar4[2].type + 1) >> 6 & 1) != 0) goto LAB_104172a7;
        }
      }
    }
    cVar5 = ovl_conversion_types_next(&types);
    local_34 = (c1_conversion *)g_arenas[5].cur;
  } while( true );
LAB_10497901:
  if ((((pcVar4->type).alias)->hidden != '\0') ||
     ((*(byte *)((int)&((pcVar4->type).alias)->target->tail + 9) & 0x40) != 0)) goto LAB_10417257;
LAB_104172a7:
  pcVar9 = (c1_symbol *)cVar10;
  if (bVar6 == 0x1a) {
    pcVar9 = ((pcVar4->type).alias)->target;
  }
  pcVar2 = pcVar9->type;
  g_arenas[5].cur = g_arenas[5].cur + 0x50;
  if (g_arenas[5].end < g_arenas[5].cur) {
    arena_grow(g_arenas + 5);
  }
  if (conv_00 == (c1_conversion *)0x0) {
    conv_00 = (c1_conversion *)0x0;
  }
  else {
    pcVar2 = ((pcVar2->extra).params)->this_type;
    *(c1_type **)((int)conv_00 + 8) = pcVar7;
    conv_00->op = '`';
    *(c1_u8 *)((int)conv_00 + 1) = '\x03';
    *(c1_u8 *)((int)conv_00 + 2) = ' ';
    *(c1_u8 *)((int)conv_00 + 4) = '\0';
    *(c1_u8 *)((int)conv_00 + 5) = '\0';
    *(c1_u8 *)((int)conv_00 + 6) = '\0';
    *(c1_u8 *)((int)conv_00 + 7) = '\0';
    *(c1_type **)((int)conv_00 + 0xc) = pcVar2;
    conv_compute_conversion(conv_00);
  }
  if ((conv_00->flags4e & 1) == 0) goto LAB_10417257;
  conv_rank_implicit_object_exact(conv_00);
  if (conv->first != (c1_conversion *)0x0) {
    iVar8 = ovl_compare_conversion_sequences(conv->first,conv_00,0);
    if (0 < iVar8) goto LAB_10417257;
    if (iVar8 == 0) {
      if (conv->second == (c1_conversion *)0x0) {
        if (local_34->rank != 0) goto LAB_10417257;
      }
      else {
        iVar8 = ovl_compare_conversion_sequences(conv->second,local_34,0);
        if (0 < iVar8) goto LAB_10417257;
        if (iVar8 != 0) goto LAB_10417316;
      }
      conv->flags4f = conv->flags4f | 2;
      goto LAB_10417257;
    }
  }
LAB_10417316:
  if ((*(c1_u32 *)cVar10.function & 0x1f) == 0x1a) {
    cVar10 = *(c1_conversion_via *)(pcVar4->type).alias;
  }
  conv->via = cVar10;
  conv->first = conv_00;
  conv->second = local_34;
  conv->flags4f = (types.seen & 1) << 1 | conv->flags4f & 0xfd;
  bVar3 = true;
  goto LAB_10417257;
}

