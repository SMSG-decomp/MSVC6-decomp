void __fastcall
fold_address_expression_part
          (uint8_t src2_kind,c2_tuple *def,c2_operand *index,c2_operand *base,c2_operand *src2,
          int redispatch,c2_tuple *t,uint32_t scale,int changed,c2_symbol *sym,int term_taken,
          c2_tuple *last_def,c2_tuple *last_sym_def,uint32_t part_size,uint32_t src2_kind_saved,
          uint8_t base_kind,c2_operand *mem,int32_t disp,
          fold_address_expression_replace_fn *replace_fn)

{
  uint8_t *puVar1;
  uint32_t uVar2;
  c2_symbol *pcVar3;
  byte bVar4;
  uint32_t form_op;
  uint uVar5;
  int iVar6;
  c2_operand *opnd;
  int iVar7;
  uint32_t const_value;
  c2_const_operand *pcVar8;
  c2_tuple *index_def;
  byte bVar9;
  uint16_t uVar10;
  c2_insert_fn *insert_fn;
  c2_operand *src1;
  
  uVar5 = (uint)src2_kind;
code_r0x1071cfae:
  opnd = base;
  if (base == (c2_operand *)0x0) goto switchD_1071cc51_caseD_4;
LAB_1071cfb6:
  base = opnd;
  if (index == (c2_operand *)0x0) goto switchD_1071cc51_caseD_4;
  if (((1 << (base_kind & 0x1f) & 6U) == 0) || (def->src->sym->def == (c2_tuple *)0x0)) {
    if ((1 << ((byte)uVar5 & 0x1f) & 6U) == 0) goto switchD_1071cc51_caseD_4;
    if (src2->sym->def == (c2_tuple *)0x0) goto switchD_1071cc51_caseD_4;
  }
  else if (((1 << ((byte)uVar5 & 0x1f) & 6U) != 0) && (src2->sym->def != (c2_tuple *)0x0)) {
    if (scale != 1) goto switchD_1071cc51_caseD_4;
    if (redispatch == 0) {
      uVar5 = 1 << (opnd->kind & 0x1f);
      if (((uVar5 & 6) != 0) && (opnd->sym->def != (c2_tuple *)0x0)) goto switchD_1071cc51_caseD_4;
      if (((uVar5 & 0x380) == 0) &&
         (((uVar5 & 0x18) == 0 &&
          (iVar6 = operand_used_between(opnd,def,t,(c2_symbol *)0x0), iVar6 != 0))))
      goto switchD_1071cc51_caseD_4;
      src1 = def->src->next;
      def->src->next = opnd;
      base = index;
      index = src1;
      goto LAB_1071cad7;
    }
    uVar5 = 1 << (index->kind & 0x1f);
    if (((uVar5 & 6) != 0) && (index->sym->def != (c2_tuple *)0x0)) goto switchD_1071cc51_caseD_4;
    if (((uVar5 & 0x380) == 0) &&
       (((uVar5 & 0x18) == 0 &&
        (iVar6 = operand_used_between(index,def,t,(c2_symbol *)0x0), iVar6 != 0))))
    goto switchD_1071cc51_caseD_4;
    base = def->src;
    def->src = index;
    index->next = base->next;
    base->next = (c2_operand *)0x0;
    goto LAB_1071cacb;
  }
  if (scale != 1) goto switchD_1071cc51_caseD_4;
  if (redispatch != 0) {
    if ((1 << (index->kind & 0x1f) & 6U) == 0) goto switchD_1071cc51_caseD_4;
    index_def = index->sym->def;
    if (index_def == (c2_tuple *)0x0) goto switchD_1071cc51_caseD_4;
    if (last_sym_def != index_def) goto switchD_1071cc51_caseD_4;
    iVar6 = tuple_in_range((c2_node *)last_sym_def,(c2_node *)def,(c2_node *)t);
    if (iVar6 != 0) goto switchD_1071cc51_caseD_4;
    opnd = def->src;
    if (((1 << (opnd->kind & 0x1f) & 6U) != 0) && (opnd->sym->def != (c2_tuple *)0x0)) {
      index->next = opnd->next;
      def->src = index;
      opnd->next = (c2_operand *)0x0;
      redispatch = 0;
      index = opnd;
      goto LAB_1071cad7;
    }
    src1 = opnd->next;
    redispatch = 0;
    index->next = src1->next;
    src1->next = (c2_operand *)0x0;
    opnd->next = index;
    index = src1;
    goto LAB_1071cad7;
  }
  if ((1 << (opnd->kind & 0x1f) & 6U) == 0) goto switchD_1071cc51_caseD_4;
  index_def = opnd->sym->def;
  if (index_def == (c2_tuple *)0x0) goto switchD_1071cc51_caseD_4;
  if (last_def != index_def) goto switchD_1071cc51_caseD_4;
  iVar6 = tuple_in_range((c2_node *)last_def,(c2_node *)def,(c2_node *)t);
  if (iVar6 != 0) goto switchD_1071cc51_caseD_4;
  base = def->src;
  if (((1 << (base->kind & 0x1f) & 6U) == 0) || (base->sym->def == (c2_tuple *)0x0)) {
    src1 = base->next;
    redispatch = 1;
    opnd->next = src1->next;
    src1->next = (c2_operand *)0x0;
    base->next = opnd;
    base = src1;
  }
  else {
    opnd->next = base->next;
    def->src = opnd;
    base->next = (c2_operand *)0x0;
    redispatch = 1;
  }
LAB_1071d394:
  opnd = index;
  if (base != (c2_operand *)0x0) goto code_r0x1071d39c;
  goto LAB_1071caeb;
code_r0x1071d39c:
  def = base->sym->def;
  if (((def != (c2_tuple *)0x0) && (def != last_def)) && (last_def = def, (def->type & 0xfff) == 4))
  {
    do {
      if (def == (c2_tuple *)0x0) break;
      opnd = index;
      switch(def->op) {
      case 0x15b:
        if (def == t) goto switchD_1071cb32_caseD_15c;
        switch(def->src->kind) {
        case '\x01':
        case '\x02':
          if (redispatch == 0) {
            node_free((c2_node *)index);
            index = def->src;
            if (index->sym->def == (c2_tuple *)0x0) {
              redispatch = 1;
            }
          }
          else {
            if (base != (c2_operand *)0x0) {
              node_free((c2_node *)base);
            }
            base = def->src;
            if (base->sym->def == (c2_tuple *)0x0) {
              redispatch = 0;
            }
          }
          def->src = (c2_operand *)0x0;
          tuple_unlink_free(def);
          changed = 1;
          opnd = index;
          break;
        case '\x03':
          if (def->src->op == 0x14a) {
            if (term_taken == 0) {
              if (redispatch == 0) {
                if (scale != 1) goto switchD_1071cc51_caseD_4;
                node_free((c2_node *)index);
                index = def->src;
              }
              else {
                if (base != (c2_operand *)0x0) {
                  node_free((c2_node *)base);
                }
                base = def->src;
              }
              def->src = (c2_operand *)0x0;
              tuple_unlink_free(def);
              changed = 1;
              term_taken = 1;
            }
            goto switchD_1071cc51_caseD_4;
          }
          if (sym != (c2_symbol *)0x0) goto switchD_1071cb32_caseD_15c;
          if (redispatch == 0) {
            if (scale != 1) goto switchD_1071cc51_caseD_4;
            node_free((c2_node *)index);
            sym = def->src->sym;
            tuple_unlink_free(def);
            changed = 1;
            redispatch = 1;
            opnd = (c2_operand *)0x0;
          }
          else {
            if (base != (c2_operand *)0x0) {
              node_free((c2_node *)base);
              base = (c2_operand *)0x0;
            }
            sym = def->src->sym;
            tuple_unlink_free(def);
            changed = 1;
            redispatch = redispatch ^ 1;
          }
          break;
        default:
          goto switchD_1071cb32_caseD_15c;
        case '\a':
          if (redispatch == 0) {
            node_free((c2_node *)index);
            redispatch = 1;
            disp = disp + (def->src->u18).lo * scale;
            tuple_unlink_free(def);
            changed = 1;
            opnd = (c2_operand *)0x0;
          }
          else {
            if (base != (c2_operand *)0x0) {
              node_free((c2_node *)base);
              base = (c2_operand *)0x0;
            }
            redispatch = 0;
            disp = (int)&((def->src->u18).reg)->fe + disp;
            tuple_unlink_free(def);
            changed = 1;
          }
        }
        goto LAB_1071cacb;
      default:
switchD_1071cb32_caseD_15c:
        redispatch = redispatch ^ 1;
        opnd = index;
        goto LAB_1071cacb;
      case 0x16d:
        src1 = def->src;
        base_kind = src1->kind;
        opnd = base;
        switch(base_kind) {
        case '\x01':
        case '\x02':
        case '\x06':
          src2 = src1->next;
          uVar5 = (uint)src2->kind;
          switch(uVar5) {
          case 1:
          case 2:
          case 6:
            if (redispatch != 0) {
              if (index == (c2_operand *)0x0) {
                materialize_memory_sources(def);
                if (base != (c2_operand *)0x0) {
                  node_free((c2_node *)base);
                }
                base = def->src;
                def->src = (c2_operand *)0x0;
                index = base->next;
                base->next = (c2_operand *)0x0;
                if (def != t) {
                  tuple_unlink_free(def);
                }
LAB_1071cc8f:
                index_def = base->sym->def;
LAB_1071cd25:
                changed = 1;
                opnd = index;
                if (index_def != (c2_tuple *)0x0) goto LAB_1071cacb;
                redispatch = 0;
                goto LAB_1071cad7;
              }
              goto code_r0x1071cfae;
            }
            if (base != (c2_operand *)0x0) goto LAB_1071cfb6;
            if (scale == 1) {
              materialize_memory_sources(def);
              base = def->src;
              node_free((c2_node *)index);
              index = def->src->next;
              base->next = (c2_operand *)0x0;
              goto LAB_1071d257;
            }
            break;
          case 3:
            if (redispatch == 0) {
              if (scale != 1) goto code_r0x1071cfae;
              if (src2->op != 0x14a) {
                if (sym == (c2_symbol *)0x0) {
                  materialize_memory_sources(def);
                  sym = def->src->next->sym;
                  goto LAB_1071d240;
                }
                goto code_r0x1071cfae;
              }
              if (base != (c2_operand *)0x0) goto LAB_1071cfb6;
              if (term_taken != 0) break;
              materialize_memory_sources(def);
              base = def->src->next;
              node_free((c2_node *)index);
              index = def->src;
              index->next = (c2_operand *)0x0;
LAB_10776565:
              def->src = (c2_operand *)0x0;
              tuple_unlink_free(def);
            }
            else {
              if (src2->op != 0x14a) {
                if (sym == (c2_symbol *)0x0) {
                  materialize_memory_sources(def);
                  sym = def->src->next->sym;
                  if (base != (c2_operand *)0x0) {
                    node_free((c2_node *)base);
                  }
                  base = def->src;
                  node_free((c2_node *)base->next);
                  base->next = (c2_operand *)0x0;
                  def->src = (c2_operand *)0x0;
                  if (def == t) goto LAB_1071cc8f;
                  tuple_unlink_free(def);
                  index_def = base->sym->def;
                  goto LAB_1071cd25;
                }
                goto code_r0x1071cfae;
              }
              if ((index != (c2_operand *)0x0) || (term_taken != 0)) goto code_r0x1071cfae;
              materialize_memory_sources(def);
              if (base != (c2_operand *)0x0) {
                node_free((c2_node *)base);
              }
              index = def->src;
              base = index->next;
              index->next = (c2_operand *)0x0;
LAB_1071ce0c:
              def->src = (c2_operand *)0x0;
              if (def != t) {
                tuple_unlink_free(def);
              }
              redispatch = 0;
            }
            changed = 1;
            term_taken = 1;
            goto LAB_1071cad7;
          case 7:
            if (redispatch != 0) {
              materialize_memory_sources(def);
              pcVar3 = (def->src->next->u18).reg;
              if (base != (c2_operand *)0x0) {
                node_free((c2_node *)base);
              }
              base = def->src;
              node_free((c2_node *)base->next);
              base->next = (c2_operand *)0x0;
LAB_1071cd01:
              disp = (int)&pcVar3->fe + disp;
              def->src = (c2_operand *)0x0;
joined_r0x1071ceb0:
              if (def != t) {
                tuple_unlink_free(def);
              }
              index_def = base->sym->def;
              goto LAB_1071cd25;
            }
            materialize_memory_sources(def);
            index = def->src;
            disp = disp + (index->next->u18).lo * scale;
            node_free((c2_node *)index->next);
            index->next = (c2_operand *)0x0;
LAB_1071d257:
            def->src = (c2_operand *)0x0;
            goto LAB_1071d25e;
          }
          break;
        case '\x03':
          src2 = src1->next;
          bVar4 = src2->kind;
          uVar5 = (uint)bVar4;
          if (((1 << (bVar4 & 0x1f) & 6U) == 0) && (src2->kind != '\x06')) {
            if (src2->kind == '\a') {
              opnd = def->src;
              if (opnd->op == 0x14a) {
                if (term_taken != 0) goto LAB_107767c6;
                if (redispatch != 0) {
                  disp = (int)&((src2->u18).reg)->fe + disp;
                  if (base != (c2_operand *)0x0) {
                    node_free((c2_node *)base);
                  }
                  base = def->src;
                  node_free((c2_node *)base->next);
LAB_1071cf10:
                  base->next = (c2_operand *)0x0;
                  goto LAB_1071ce0c;
                }
                if (scale != 1) goto LAB_107767c6;
                disp = (int)&((src2->u18).reg)->fe + disp;
                node_free((c2_node *)index);
                index = def->src;
                node_free((c2_node *)index->next);
                index->next = (c2_operand *)0x0;
                def->src = (c2_operand *)0x0;
                tuple_unlink_free(def);
                changed = 1;
                redispatch = 1;
                term_taken = 1;
              }
              else {
                if (sym != (c2_symbol *)0x0) {
LAB_107767c6:
                  fold_address_expression_part
                            (bVar4,def,index,base,src2,redispatch,t,scale,changed,sym,term_taken,
                             last_def,last_sym_def,part_size,uVar5,base_kind,mem,disp,replace_fn);
                  return;
                }
                if (redispatch != 0) {
                  sym = opnd->sym;
                  disp = (int)&((src2->u18).reg)->fe + disp;
                  if (base != (c2_operand *)0x0) {
                    node_free((c2_node *)base);
                    base = (c2_operand *)0x0;
                  }
                  node_free((c2_node *)def->src->next);
                  node_free((c2_node *)def->src);
                  def->src = (c2_operand *)0x0;
                  if (def != t) {
                    tuple_unlink_free(def);
                  }
                  changed = 1;
                  redispatch = 0;
                  goto LAB_1071cad7;
                }
                if (scale != 1) goto LAB_107767c6;
                sym = opnd->sym;
                disp = (int)&((src2->u18).reg)->fe + disp;
                node_free((c2_node *)index);
                index = (c2_operand *)0x0;
                tuple_unlink_free(def);
                changed = 1;
                redispatch = 1;
              }
              goto LAB_1071d394;
            }
          }
          else {
            if (redispatch != 0) {
              if (def->src->op != 0x14a) {
                if (sym != (c2_symbol *)0x0) goto LAB_107767c6;
                materialize_memory_sources(def);
                sym = def->src->sym;
                if (base != (c2_operand *)0x0) {
                  node_free((c2_node *)base);
                }
                base = def->src->next;
                node_free((c2_node *)def->src);
                def->src = (c2_operand *)0x0;
                goto joined_r0x1071ceb0;
              }
              if ((index != (c2_operand *)0x0) || (term_taken != 0)) goto LAB_107767c6;
              materialize_memory_sources(def);
              if (base != (c2_operand *)0x0) {
                node_free((c2_node *)base);
              }
              base = def->src;
              index = base->next;
              goto LAB_1071cf10;
            }
            if (scale != 1) goto LAB_107767c6;
            if (def->src->op != 0x14a) {
              if (sym != (c2_symbol *)0x0) goto LAB_107767c6;
              materialize_memory_sources(def);
              sym = def->src->sym;
              goto LAB_1077660f;
            }
            if (base != (c2_operand *)0x0) goto LAB_1071cfb6;
            if (term_taken == 0) {
              materialize_memory_sources(def);
              node_free((c2_node *)index);
              base = def->src;
              index = base->next;
              base->next = (c2_operand *)0x0;
              goto LAB_10776565;
            }
          }
          break;
        default:
          goto switchD_1071cb32_caseD_15c;
        case '\a':
          bVar4 = src1->next->kind;
          if (((1 << (bVar4 & 0x1f) & 6U) == 0) && (bVar4 != 6)) {
            redispatch = redispatch ^ 1;
            opnd = index;
            goto LAB_1071cacb;
          }
          if (redispatch != 0) {
            materialize_memory_sources(def);
            pcVar3 = (def->src->u18).reg;
            if (base != (c2_operand *)0x0) {
              node_free((c2_node *)base);
            }
            base = def->src->next;
            node_free((c2_node *)def->src);
            goto LAB_1071cd01;
          }
          materialize_memory_sources(def);
          disp = disp + (def->src->u18).lo * scale;
LAB_1077660f:
          node_free((c2_node *)index);
          index = def->src->next;
          def->src->next = (c2_operand *)0x0;
LAB_1071d25e:
          tuple_unlink_free(def);
          index_def = index->sym->def;
LAB_1071d382:
          changed = 1;
          if (index_def != (c2_tuple *)0x0) goto LAB_1071cad7;
          redispatch = 1;
          goto LAB_1071d394;
        }
        break;
      case 0x16e:
        if ((def->src->next->kind == '\a') &&
           ((bVar4 = def->src->kind, (1 << (bVar4 & 0x1f) & 6U) != 0 || (bVar4 == 6)))) {
          if (redispatch == 0) {
            materialize_memory_sources(def);
            disp = disp - (def->src->next->u18).lo * scale;
LAB_1071d240:
            node_free((c2_node *)index);
            index = def->src;
            node_free((c2_node *)index->next);
            index->next = (c2_operand *)0x0;
            goto LAB_1071d257;
          }
          materialize_memory_sources(def);
          disp = disp - (def->src->next->u18).lo;
          if (base != (c2_operand *)0x0) {
            node_free((c2_node *)base);
          }
          base = def->src;
          node_free((c2_node *)base->next);
          base->next = (c2_operand *)0x0;
          def->src = (c2_operand *)0x0;
          if (def != t) {
            tuple_unlink_free(def);
          }
          changed = 1;
          if (base->sym->def != (c2_tuple *)0x0) goto LAB_1071cacb;
          redispatch = 0;
          goto LAB_1071cad7;
        }
        break;
      case 0x16f:
        opnd = def->src->next;
        if (((opnd->kind == '\a') &&
            ((bVar4 = def->src->kind, (1 << (bVar4 & 0x1f) & 6U) != 0 || (bVar4 == 6)))) &&
           ((uVar2 = (opnd->u18).lo, uVar2 == 1 || (((uVar2 == 2 || (uVar2 == 4)) || (uVar2 == 8))))
           )) {
          if (redispatch == 0) {
            if (scale != 1) break;
            materialize_memory_sources(def);
            node_free((c2_node *)index);
            index = def->src;
            node_free((c2_node *)index->next);
            index->next = (c2_operand *)0x0;
            def->src = (c2_operand *)0x0;
            tuple_unlink_free(def);
            index_def = index->sym->def;
            scale = uVar2;
            goto LAB_1071d382;
          }
          if ((index == (c2_operand *)0x0) || (scale == 1)) {
            materialize_memory_sources(def);
            if (base != (c2_operand *)0x0) {
              node_free((c2_node *)base);
            }
            opnd = def->src;
            node_free((c2_node *)opnd->next);
            opnd->next = (c2_operand *)0x0;
            def->src = (c2_operand *)0x0;
            if (def != t) {
              tuple_unlink_free(def);
            }
            index_def = opnd->sym->def;
            scale = uVar2;
LAB_1071d30c:
            changed = 1;
            base = index;
            if (index_def != (c2_tuple *)0x0) {
              redispatch = 0;
              index = opnd;
              goto LAB_1071cad7;
            }
            goto LAB_1071cacb;
          }
        }
        break;
      case 0x171:
        opnd = def->src->next;
        if (((opnd->kind == '\a') &&
            ((bVar4 = def->src->kind, (1 << (bVar4 & 0x1f) & 6U) != 0 || (bVar4 == 6)))) &&
           ((uVar2 = (opnd->u18).lo, uVar2 == 1 || ((uVar2 == 2 || (uVar2 == 3)))))) {
          if (redispatch == 0) {
            if (scale == 1) {
              materialize_memory_sources(def);
              scale = 1 << ((byte)uVar2 & 0x1f);
              node_free((c2_node *)index);
              index = def->src;
              node_free((c2_node *)index->next);
              index->next = (c2_operand *)0x0;
              def->src = (c2_operand *)0x0;
              tuple_unlink_free(def);
              index_def = index->sym->def;
              goto LAB_1071d382;
            }
          }
          else if ((index == (c2_operand *)0x0) || (scale == 1)) {
            materialize_memory_sources(def);
            if (base != (c2_operand *)0x0) {
              node_free((c2_node *)base);
            }
            opnd = def->src;
            node_free((c2_node *)opnd->next);
            opnd->next = (c2_operand *)0x0;
            def->src = (c2_operand *)0x0;
            if (def != t) {
              tuple_unlink_free(def);
            }
            index_def = opnd->sym->def;
            scale = 1 << ((byte)uVar2 & 0x1f);
            goto LAB_1071d30c;
          }
        }
      }
switchD_1071cc51_caseD_4:
      redispatch = redispatch ^ 1;
      opnd = index;
LAB_1071cacb:
      index = opnd;
      if (redispatch != 0) goto LAB_1071d394;
LAB_1071cad7:
      if ((((index == (c2_operand *)0x0) || (def = index->sym->def, def == (c2_tuple *)0x0)) ||
          (def == last_sym_def)) || (last_sym_def = def, (def->type & 0xfff) != 4)) break;
    } while( true );
  }
  opnd = index;
  if (base == (c2_operand *)0x0) {
LAB_1071caeb:
    index = opnd;
    if (opnd == (c2_operand *)0x0) {
      form_op = 0x14b;
      if (sym == (c2_symbol *)0x0) {
        form_op = 0x146;
      }
    }
    else {
      opnd->flags = opnd->flags & 0xef;
      opnd->next = (c2_operand *)0x0;
      if ((int)scale < 2) {
        form_op = 0x14c;
        index = (c2_operand *)0x0;
        base = opnd;
      }
      else {
        form_op = 0x14f;
      }
    }
  }
  else {
    base->next = (c2_operand *)0x0;
    base->flags = base->flags & 0xef;
    if (base->kind == '\x03') {
      if (index == (c2_operand *)0x0) {
        form_op = 0x14a;
      }
      else {
        index->next = (c2_operand *)0x0;
        index->flags = index->flags & 0xef;
        form_op = 0x14e;
      }
    }
    else if (index == (c2_operand *)0x0) {
      form_op = 0x14c;
    }
    else {
      index->next = (c2_operand *)0x0;
      index->flags = index->flags & 0xef;
      form_op = 0x14d;
    }
  }
  if (changed == 0) {
    return;
  }
  iVar6 = disp >> 0x1f;
  bVar4 = (byte)((int)scale >> 1);
  if (mem != (c2_operand *)0x0) {
    switch(form_op) {
    case 0x146:
      opnd = mem->base;
      puVar1 = &opnd->flags;
      *puVar1 = *puVar1 & 0xdf;
      tuple_remove_src(t,opnd);
      mem->base = (c2_operand *)0x0;
      mem->disp = disp;
      mem->op = 0x152;
      return;
    default:
      ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\x86\\addr.c",0x402);
    case 0x14a:
      iVar7 = disp_within_symbol(base->sym,disp);
      if (iVar7 != 0) {
        uVar10 = mem->type;
        const_value = (uint32_t)symbol_get_part(base->sym,uVar10,part_size,disp);
        opnd = operand_new_sym(0x14a,uVar10,(c2_symbol *)const_value);
        opnd->flags11 = (mem->flags11 ^ opnd->flags11) & 8 ^ opnd->flags11;
        opnd->flags = (mem->flags ^ opnd->flags) & 0x40 ^ opnd->flags;
        (*replace_fn)(t,mem,opnd);
        node_free((c2_node *)base);
        return;
      }
      insert_fn = tuple_insert_before;
      opnd = mem->base;
      pcVar8 = operand_new_intconst(0x1004,disp,iVar6);
      break;
    case 0x14b:
      iVar7 = disp_within_symbol(sym,disp);
      if (iVar7 != 0) {
        uVar10 = mem->type;
        const_value = (uint32_t)symbol_get_part(sym,uVar10,part_size,disp);
        opnd = operand_new_sym(0x14b,uVar10,(c2_symbol *)const_value);
        opnd->flags11 = (mem->flags11 ^ opnd->flags11) & 8 ^ opnd->flags11;
        opnd->flags = (mem->flags ^ opnd->flags) & 0x40 ^ opnd->flags;
        (*replace_fn)(t,mem,opnd);
        return;
      }
      insert_fn = tuple_insert_before;
      opnd = mem->base;
      pcVar8 = operand_new_intconst(0x1004,disp,iVar6);
      base = operand_new_symaddr(0x14b,sym);
      break;
    case 0x14c:
      opnd = operand_new_mem(0x14c,mem->type,sym,disp,base,(c2_operand *)0x0,mem->tag);
      bVar9 = (mem->flags11 ^ opnd->flags11) & 7 ^ opnd->flags11;
      bVar4 = mem->flags;
      opnd->flags11 = (bVar9 ^ mem->flags11) & 8 ^ bVar9;
      opnd->flags = (bVar4 ^ opnd->flags) & 0x40 ^ opnd->flags;
      (*replace_fn)(t,mem,opnd);
      return;
    case 0x14d:
      if ((((int)scale < 2) && (base->kind != '\x01')) && (index->kind != '\x01')) {
        opnd = mem->base;
        index_def = tuple_new_binary(0x2d,base->type,opnd,base,index,tuple_insert_before,t);
        opnd->sym->def = index_def;
        mem->disp = disp;
        mem->base_sym = sym;
        return;
      }
      opnd = operand_new_mem(0x14d,mem->type,sym,disp,base,index,mem->tag);
      if (7 < (int)scale) {
        bVar4 = 3;
      }
      bVar9 = (opnd->flags ^ bVar4) & 0xf ^ opnd->flags;
      bVar4 = (mem->flags11 ^ opnd->flags11) & 7 ^ opnd->flags11;
      opnd->flags11 = (bVar4 ^ mem->flags11) & 8 ^ bVar4;
      opnd->flags = (mem->flags ^ bVar9) & 0x40 ^ bVar9;
      (*replace_fn)(t,mem,opnd);
      return;
    case 0x14e:
      opnd = operand_new_mem(0x14e,mem->type,base->sym,disp,(c2_operand *)0x0,index,mem->tag);
      if (7 < (int)scale) {
        bVar4 = 3;
      }
      bVar9 = (bVar4 ^ opnd->flags) & 0xf ^ opnd->flags;
      bVar4 = mem->flags;
      opnd->flags11 = (mem->flags11 ^ opnd->flags11) & 8 ^ opnd->flags11;
      opnd->flags = (bVar4 ^ bVar9) & 0x40 ^ bVar9;
      (*replace_fn)(t,mem,opnd);
      node_free((c2_node *)base);
      return;
    case 0x14f:
      opnd = operand_new_mem(0x14f,mem->type,sym,disp,(c2_operand *)0x0,index,mem->tag);
      if (7 < (int)scale) {
        bVar4 = 3;
      }
      bVar4 = (bVar4 ^ opnd->flags) & 0xf ^ opnd->flags;
      bVar9 = (mem->flags11 ^ opnd->flags11) & 7 ^ opnd->flags11;
      opnd->flags11 = (bVar9 ^ mem->flags11) & 8 ^ bVar9;
      opnd->flags = (mem->flags ^ bVar4) & 0x40 ^ bVar4;
      (*replace_fn)(t,mem,opnd);
      return;
    }
    index_def = tuple_new_binary(0x16d,0x1004,opnd,base,pcVar8,insert_fn,t);
    opnd->sym->def = index_def;
    return;
  }
  switch(form_op) {
  case 0x146:
    uVar10 = t->type;
    t->op = 1;
    break;
  default:
    ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\x86\\addr.c",0x49b);
  case 0x14a:
    t->op = 0x12;
    if (disp == 0) {
      tuple_append_src(t,base);
      return;
    }
    iVar7 = disp_within_symbol(base->sym,disp);
    if (iVar7 != 0) {
      const_value = (uint32_t)symbol_get_part(base->sym,base->sym->type,4,disp);
      opnd = operand_new_symaddr(0x14a,(c2_symbol *)const_value);
      tuple_append_src(t,opnd);
      node_free((c2_node *)base);
      return;
    }
    t->op = 0x16d;
    tuple_append_src(t,base);
    uVar10 = 0x1004;
    break;
  case 0x14b:
    t->op = 1;
    iVar6 = disp_within_symbol(sym,disp);
    if (iVar6 == 0) {
      opnd = operand_new_addr(0x150,t->type,sym,disp,(c2_operand *)0x0,(c2_operand *)0x0);
      tuple_append_src(t,opnd);
      return;
    }
    goto joined_r0x10776bc5;
  case 0x14c:
    if ((sym == (c2_symbol *)0x0) && (disp == 0)) {
      t->op = 1;
      tuple_append_src(t,base);
      return;
    }
    opnd = t->dst;
    if ((((((1 << (opnd->kind & 0x1f) & 6U) == 0) || (opnd->sym->def == (c2_tuple *)0x0)) ||
         ((base->kind == '\x01' && (base->sym->def == (c2_tuple *)0x0)))) &&
        ((base->kind != '\x01' || (base->sym != opnd->sym)))) ||
       ((sym != (c2_symbol *)0x0 && (iVar6 = disp_within_symbol(sym,disp), iVar6 == 0)))) {
      t->op = 0x12;
      opnd = operand_new_addr(0x14c,t->type,sym,disp,base,(c2_operand *)0x0);
      tuple_append_src(t,opnd);
      return;
    }
    tuple_append_src(t,base);
    if (sym == (c2_symbol *)0x0) {
      if (disp < 1) {
        t->op = 0x32;
        disp = -disp;
      }
      else {
        t->op = 0x2d;
      }
      pcVar8 = operand_new_intconst(t->type,disp,disp >> 0x1f);
      tuple_append_src(t,pcVar8);
      return;
    }
    t->op = 0x2d;
joined_r0x10776bc5:
    if (disp != 0) {
      sym = symbol_get_part(sym,sym->type,4,disp);
    }
    opnd = operand_new_symaddr(0x14b,sym);
    tuple_append_src(t,opnd);
    return;
  case 0x14d:
    if ((((((int)scale < 2) && (disp == 0)) && (sym == (c2_symbol *)0x0)) &&
        (((opnd = t->dst, (1 << (opnd->kind & 0x1f) & 6U) != 0 &&
          (const_value = (uint32_t)opnd->sym, ((c2_symbol *)const_value)->def != (c2_tuple *)0x0))
         || ((base->kind == '\x01' &&
             (const_value = (uint32_t)opnd->sym, (c2_symbol *)const_value == base->sym)))))) &&
       (((base->kind != '\x01' || (((base->u18).reg)->cls != '\x02')) ||
        ((index->kind != '\x01' ||
         ((((index->u18).reg)->cls != '\x02' || (base->sym == (c2_symbol *)const_value)))))))) {
      t->op = 0x2d;
      tuple_append_src(t,base);
      tuple_append_src(t,index);
      if ((1 << (index->kind & 0x1f) & 6U) == 0) {
        return;
      }
      index_def = index->sym->def;
      if (index_def == (c2_tuple *)0x0) {
        return;
      }
      if (index_def->op != 1) {
        return;
      }
      tuple_replace_src(t,index,index_def->src);
      tuple_unlink_free(index_def);
      return;
    }
    t->op = 0x12;
    opnd = operand_new_addr(0x14d,t->type,sym,disp,base,index);
    if ((int)scale < 8) {
      opnd->flags = (bVar4 ^ opnd->flags) & 0xf ^ opnd->flags;
      tuple_append_src(t,opnd);
      return;
    }
LAB_1071dad8:
    opnd->flags = (opnd->flags ^ 3) & 0xf ^ opnd->flags;
    tuple_append_src(t,opnd);
    return;
  case 0x14e:
    const_value = (uint32_t)base->sym;
    t->op = 0x12;
    opnd = operand_new_addr(0x14e,t->type,(c2_symbol *)const_value,disp,(c2_operand *)0x0,index);
    if (7 < (int)scale) {
      bVar4 = 3;
    }
    opnd->flags = (bVar4 ^ opnd->flags) & 0xf ^ opnd->flags;
    tuple_append_src(t,opnd);
    node_free((c2_node *)base);
    return;
  case 0x14f:
    if (((sym != (c2_symbol *)0x0) || (disp != 0)) ||
       ((((opnd = t->dst, (1 << (opnd->kind & 0x1f) & 6U) == 0 ||
          (opnd->sym->def == (c2_tuple *)0x0)) ||
         ((index->kind == '\x01' && (index->sym->def == (c2_tuple *)0x0)))) &&
        ((index->kind != '\x01' || (index->sym != opnd->sym)))))) {
      t->op = 0x12;
      opnd = operand_new_addr(0x14f,t->type,sym,disp,(c2_operand *)0x0,index);
      if ((int)scale < 8) {
        opnd->flags = (bVar4 ^ opnd->flags) & 0xf ^ opnd->flags;
        tuple_append_src(t,opnd);
        return;
      }
      goto LAB_1071dad8;
    }
    t->op = 0x2a;
    tuple_append_src(t,index);
    if ((int)scale < 8) {
      uVar10 = t->type;
      iVar6 = (int)scale >> 0x1f;
      disp = (int)scale >> 1;
    }
    else {
      uVar10 = t->type;
      iVar6 = 0;
      disp = 3;
    }
  }
  pcVar8 = operand_new_intconst(uVar10,disp,iVar6);
  tuple_append_src(t,pcVar8);
  return;
}

