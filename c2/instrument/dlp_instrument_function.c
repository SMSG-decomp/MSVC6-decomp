void __fastcall dlp_instrument_function(c2_function *fn)

{
  byte bVar1;
  ushort uVar2;
  c2_fe_symbol *sym;
  c2_cfg *pcVar3;
  c2_tuple *anchor;
  c2_operand *pcVar4;
  c2_tuple *pcVar5;
  bool bVar6;
  uint32_t uVar7;
  c2_fe_symbol *s;
  char *pcVar8;
  c2_operand *base;
  c2_operand *dst;
  c2_symbol *pcVar9;
  c2_const_operand *pcVar10;
  c2_operand *pcVar11;
  c2_tuple *pcVar12;
  uint uVar13;
  c2_tuple *pcVar14;
  int16_t kind;
  int arena;
  uint8_t f;
  uint32_t attrs;
  c2_operand *local_20;
  c2_tuple *local_14;
  c2_const_operand *local_4;
  
  if (((fn->flags & 0x800) == 0) && (sym = fn->fsym, (sym->attrs & 0x400) == 0)) {
    attrs = 0;
    f = '\x04';
    arena = 1;
    uVar13 = (uint)g_ptr_type;
    kind = 1;
    uVar7 = type_class_to_symbol_class(g_ptr_type);
    s = fe_symbol_new_local_cur((uint16_t)uVar7,uVar13 & 0xfff,kind,arena,f,attrs);
    pcVar8 = decorate_c_name(s,"_dlpPtr",0);
    s->name = pcVar8;
    base = operand_for_fe_symbol(s);
    base->flags = base->flags | 0x10;
    dst = operand_new_mem(0x14c,0x2004,(c2_symbol *)0x0,0,base,(c2_operand *)0x0,1);
    pcVar3 = fn->cfg;
    bVar6 = false;
    local_14 = (c2_tuple *)0x0;
    dst->flags = dst->flags | 0x10;
    for (anchor = pcVar3->first->head; anchor != (c2_tuple *)0x0; anchor = anchor->next) {
      bVar1 = anchor->kind;
      if (((((1 << (bVar1 & 0x1f) & 0xa0000U) == 0) && (bVar1 != 0x1a)) && (bVar1 != 0x15)) &&
         (bVar1 != 0x18)) {
        if ((anchor->flags & 1) != 0) {
          if (local_14 == (c2_tuple *)0x0) {
            local_14 = anchor->prev;
          }
          local_20 = anchor->src;
joined_r0x10795f40:
          pcVar11 = local_20;
          if (pcVar11 != (c2_operand *)0x0) {
            local_20 = pcVar11->next;
            if ((1 << (pcVar11->kind & 0x1f) & 0x60U) != 0) {
              if (((uint)pcVar11->sym & 0x3ffff) == 0) {
                if ((pcVar11->kind != 6) || (uVar7 = dlp_type_code(pcVar11->type), uVar7 == 0))
                goto joined_r0x10795f40;
                pcVar9 = (c2_symbol *)dlp_pack_site_id(0,0,uVar7);
                pcVar11->sym = pcVar9;
              }
              uVar2 = anchor->line;
              if (uVar2 != 0) {
                g_current_line_abs = fn->line_base + (uint)uVar2;
                g_cur_line = uVar2;
              }
              if (pcVar11->kind == '\x06') {
                pcVar9 = (c2_symbol *)((uint)pcVar11->sym & 0x3fffffff);
              }
              else {
                pcVar9 = (c2_symbol *)((uint)pcVar11->sym & 0x3fffffff | 0x40000000);
              }
              pcVar4 = pcVar11->base;
              pcVar11->sym = pcVar9;
              if (((1 << (pcVar4->kind & 0x1f) & 6U) != 0) &&
                 (pcVar5 = pcVar4->sym->def, pcVar5 != (c2_tuple *)0x0)) {
                instrument_split_result_through_temp(pcVar5);
                local_20 = pcVar11->next;
              }
              tuple_new(0x1ad,0x2004,dst,pcVar4,tuple_insert_before,anchor);
              pcVar10 = operand_new_intconst(0x2004,(uint32_t)pcVar11->sym,0);
              tuple_new(0x1ad,0x2004,dst,pcVar10,tuple_insert_before,anchor);
              bVar6 = true;
            }
            goto joined_r0x10795f40;
          }
          local_20 = anchor->dst;
joined_r0x10796048:
          do {
            pcVar11 = local_20;
            if (pcVar11 == (c2_operand *)0x0) break;
            local_20 = pcVar11->next;
            if ((1 << (pcVar11->kind & 0x1f) & 0x60U) != 0) {
              if (((uint)pcVar11->sym & 0x3ffff) == 0) {
                uVar7 = dlp_type_code(pcVar11->type);
                if (uVar7 == 0) goto joined_r0x10796048;
                pcVar9 = (c2_symbol *)dlp_pack_site_id(0,0,uVar7);
                pcVar11->sym = pcVar9;
              }
              uVar2 = anchor->line;
              if (uVar2 != 0) {
                g_current_line_abs = fn->line_base + (uint)uVar2;
                g_cur_line = uVar2;
              }
              pcVar4 = pcVar11->base;
              bVar1 = pcVar4->kind;
              pcVar11->sym = (c2_symbol *)((uint)pcVar11->sym & 0x3fffffff | 0x80000000);
              if (((1 << (bVar1 & 0x1f) & 6U) != 0) &&
                 (pcVar5 = pcVar4->sym->def, pcVar5 != (c2_tuple *)0x0)) {
                instrument_split_result_through_temp(pcVar5);
                local_20 = pcVar11->next;
              }
              tuple_new(0x1ad,0x2004,dst,pcVar4,tuple_insert_before,anchor);
              pcVar10 = operand_new_intconst(0x2004,(uint32_t)pcVar11->sym,0);
              tuple_new(0x1ad,0x2004,dst,pcVar10,tuple_insert_before,anchor);
              bVar6 = true;
            }
          } while( true );
        }
      }
      else {
        if (bVar6) {
          pcVar5 = local_14->next;
          pcVar14 = (c2_tuple *)0x0;
          bVar6 = false;
          local_20 = (c2_operand *)0x0;
          for (; ((pcVar5 != (c2_tuple *)0x0 &&
                  (bVar1 = pcVar5->kind, (1 << (bVar1 & 0x1f) & 0xa0000U) == 0)) &&
                 ((bVar1 != 0x1a && (bVar1 != 0x15)))); pcVar5 = pcVar5->next) {
            if (pcVar5->op == 0x1ad) {
              uVar2 = pcVar5->line;
              if (uVar2 != 0) {
                g_current_line_abs = fn->line_base + (uint)uVar2;
                g_cur_line = uVar2;
              }
              if (pcVar14 == (c2_tuple *)0x0) {
                local_4 = operand_new_intconst(0x2004,0,0);
                pcVar11 = operand_new_codeaddr(0x153,sym);
                pcVar14 = tuple_new_unary_temp(0x15a,0x2004,local_4,tuple_insert_before,pcVar5);
                pcVar12 = tuple_new_unary_temp(0x15a,0x2004,pcVar11,tuple_insert_before,pcVar5);
                pcVar14 = tuple_new_intrinsic(400,0x2004,base,pcVar12->dst,pcVar14->dst,
                                              (c2_operand *)0x0,(c2_operand *)0x0,0x186,
                                              tuple_insert_before,pcVar5);
              }
              pcVar5->dst->disp = (int32_t)local_20;
              local_20 = (c2_operand *)((int)local_20 + 4);
              (local_4->u18).reg = (c2_symbol *)local_20;
              local_4->tag = (int)local_20 >> 0x1f;
            }
            else if (bVar1 == 0xe) {
              pcVar14 = (c2_tuple *)0x0;
              local_20 = (c2_operand *)0x0;
            }
          }
        }
        local_14 = (c2_tuple *)0x0;
      }
    }
    node_free((c2_node *)base);
    node_free((c2_node *)dst);
  }
  return;
}

