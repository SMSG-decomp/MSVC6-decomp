void __fastcall conv_rule_pattern_target(c1_conversion *conv)

{
  c1_u8 cVar1;
  ushort uVar2;
  c1_symbol *cls;
  c1_type *pcVar3;
  bool bVar4;
  c1_sym_link *pcVar5;
  char cVar6;
  byte bVar7;
  c1_type *pcVar8;
  c1_symbol *sym;
  int iVar9;
  c1_symbol *pcVar10;
  c1_conversion_via cVar11;
  fe_name **ppfVar12;
  c1_conversion *conv_00;
  c1_conversion *pcStack_34;
  c1_sym_link *next_link;
  c1_conversion_type_iter cStack_18;
  
  uVar2 = conv->target->code;
  if ((uVar2 != 0x800) && ((uVar2 < 0x801 || (0x802 < uVar2)))) {
    iVar9 = conv->source_class;
    if (iVar9 == 6) {
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
      bVar4 = false;
      pcVar8 = type_pointer_with_qualifiers(conv->source,0);
      class_conversion_functions_begin(&cStack_18,cls);
      cVar6 = ovl_conversion_types_next(&cStack_18);
      pcStack_34 = (c1_conversion *)g_arenas[5].cur;
      do {
        g_arenas[5].cur = &pcStack_34->op;
        if (cVar6 == '\0') {
          bVar7 = conv->flags4f & 2;
          if (bVar7 == 0) {
            if (bVar4) {
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
          if (bVar7 != 0) {
            conv->note = 0x179a;
            conv->note_fn = (void *)0x0;
            return;
          }
          conv->note = 0x1799;
          return;
        }
        if (((conv->flags & 0x40) == 0) ||
           ((bVar7 = (byte)(cStack_18.type)->code, (char)bVar7 < '\0' && ((bVar7 & 0x8f) == 0x80))))
        {
          g_arenas[5].cur = &pcStack_34[1].op;
          if (g_arenas[5].end < g_arenas[5].cur) {
            arena_grow(g_arenas + 5);
          }
          cVar6 = '\0';
          if (pcStack_34 == (c1_conversion *)0x0) {
            pcStack_34 = (c1_conversion *)0x0;
          }
          else {
            if ((conv->mode == '\x02') || (conv->mode == '\x03')) {
              cVar6 = '\x01';
            }
            bVar7 = conv->flags;
            cVar1 = conv->op;
            pcStack_34->target = conv->target;
            pcStack_34->op = cVar1;
            pcStack_34->mode = cVar6 + '\x01';
            pcStack_34->flags = bVar7 | 0x28;
            pcStack_34->expr = (c1_node *)0x0;
            pcStack_34->source = cStack_18.type;
            conv_compute_conversion(pcStack_34);
          }
          if ((pcStack_34->flags4e & 1) != 0) {
            next_link = (c1_sym_link *)0x0;
            sym = class_find_conversion_function(cStack_18.type,cls);
            ppfVar12 = &sym->name;
            if (((ppfVar12 != (fe_name **)0x0) &&
                (iVar9 = sym_is_data_or_function_2(sym), next_link = (c1_sym_link *)ppfVar12,
                (char)iVar9 == '\0')) && ((sym->kind & 0x1f) != 0x1a)) {
              next_link = (c1_sym_link *)sym->type;
            }
LAB_10417257:
            while ((pcVar5 = next_link, ppfVar12 != (fe_name **)0x0 &&
                   (next_link != (c1_sym_link *)0x0))) {
              iVar9 = sym_is_data_or_function_2(sym);
              conv_00 = (c1_conversion *)g_arenas[5].cur;
              if (((char)iVar9 == '\0') && ((sym->kind & 0x1f) != 0x1a)) {
                next_link = next_link->next;
              }
              else {
                next_link = (c1_sym_link *)0x0;
              }
              cVar11.function = (c1_symbol *)&pcVar5[-1].position;
              bVar7 = (byte)pcVar5[-1].position & 0x1f;
              if (bVar7 == 0x1a) goto LAB_10497901;
              if (((byte)~*(byte *)((int)&pcVar5[2].type + 1) >> 6 & 1) != 0) goto LAB_104172a7;
            }
          }
        }
        cVar6 = ovl_conversion_types_next(&cStack_18);
        pcStack_34 = (c1_conversion *)g_arenas[5].cur;
      } while( true );
    }
    switch(uVar2) {
    case 0x803:
      if ((iVar9 != 2) && (iVar9 != 5)) {
        conv->rank = 0x70;
        conv->note = 0x178f;
        return;
      }
      break;
    case 0x804:
      if (iVar9 != 4) {
        conv->rank = 0x70;
        conv->note = 0x1790;
        return;
      }
      break;
    case 0x805:
      if ((iVar9 != 2) && ((iVar9 < 4 || (5 < iVar9)))) {
        conv->rank = 0x70;
        conv->note = 0x1791;
        return;
      }
      break;
    default:
      goto LAB_10497a3d;
    case 0x807:
      if ((iVar9 != 8) && (iVar9 != 10)) {
        conv->rank = 0x70;
        conv->note = 0x1792;
        return;
      }
    }
    conv->rank = 0;
    conv->build = conv_build_pattern_operand;
    conv->note = 0x17d4;
    return;
  }
  conv->rank = 0;
  conv->build = conv_build_template_parameter_operand;
  conv->note = 0x17d4;
LAB_10497a3d:
  return;
LAB_10497901:
  if ((((pcVar5->type).alias)->hidden != '\0') ||
     ((*(byte *)((int)&((pcVar5->type).alias)->target->tail + 9) & 0x40) != 0)) goto LAB_10417257;
LAB_104172a7:
  pcVar10 = (c1_symbol *)cVar11;
  if (bVar7 == 0x1a) {
    pcVar10 = ((pcVar5->type).alias)->target;
  }
  pcVar3 = pcVar10->type;
  g_arenas[5].cur = g_arenas[5].cur + 0x50;
  if (g_arenas[5].end < g_arenas[5].cur) {
    arena_grow(g_arenas + 5);
  }
  if (conv_00 == (c1_conversion *)0x0) {
    conv_00 = (c1_conversion *)0x0;
  }
  else {
    pcVar3 = ((pcVar3->extra).params)->this_type;
    *(c1_type **)((int)conv_00 + 8) = pcVar8;
    conv_00->op = '`';
    *(c1_u8 *)((int)conv_00 + 1) = '\x03';
    *(c1_u8 *)((int)conv_00 + 2) = ' ';
    *(c1_u8 *)((int)conv_00 + 4) = '\0';
    *(c1_u8 *)((int)conv_00 + 5) = '\0';
    *(c1_u8 *)((int)conv_00 + 6) = '\0';
    *(c1_u8 *)((int)conv_00 + 7) = '\0';
    *(c1_type **)((int)conv_00 + 0xc) = pcVar3;
    conv_compute_conversion(conv_00);
  }
  if ((conv_00->flags4e & 1) == 0) goto LAB_10417257;
  conv_rank_implicit_object_exact(conv_00);
  if (conv->first != (c1_conversion *)0x0) {
    iVar9 = ovl_compare_conversion_sequences(conv->first,conv_00,0);
    if (0 < iVar9) goto LAB_10417257;
    if (iVar9 == 0) {
      if (conv->second == (c1_conversion *)0x0) {
        if (pcStack_34->rank != 0) goto LAB_10417257;
      }
      else {
        iVar9 = ovl_compare_conversion_sequences(conv->second,pcStack_34,0);
        if (0 < iVar9) goto LAB_10417257;
        if (iVar9 != 0) goto LAB_10417316;
      }
      conv->flags4f = conv->flags4f | 2;
      goto LAB_10417257;
    }
  }
LAB_10417316:
  if ((*(c1_u32 *)cVar11.function & 0x1f) == 0x1a) {
    cVar11 = *(c1_conversion_via *)(pcVar5->type).alias;
  }
  conv->via = cVar11;
  conv->first = conv_00;
  conv->second = pcStack_34;
  conv->flags4f = (cStack_18.seen & 1) << 1 | conv->flags4f & 0xfd;
  bVar4 = true;
  goto LAB_10417257;
}

