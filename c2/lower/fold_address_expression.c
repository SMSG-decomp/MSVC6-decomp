void __fastcall
fold_address_expression
          (c2_tuple *t,c2_tuple *def_tuple,c2_operand *addr,int32_t disp,
          fold_address_expression_replace_fn *replace_fn)

{
  uint8_t *puVar1;
  ushort uVar2;
  uint32_t uVar3;
  byte bVar4;
  uint32_t mem_op;
  c2_operand *new_base;
  uint uVar5;
  int iVar6;
  int factor;
  c2_const_operand *pcVar7;
  c2_tuple *pcVar8;
  byte bVar9;
  uint16_t uVar10;
  c2_operand *base_op;
  c2_operand *index_op;
  c2_operand *new_index;
  uint redispatch;
  int iVar11;
  c2_symbol *pcVar12;
  int iVar13;
  uint part_size;
  c2_tuple *last_def;
  int scale;
  c2_tuple *last_sym_def;
  c2_insert_fn *insert_fn;
  c2_operand *def_src;
  
  index_op = (c2_operand *)0x0;
  base_op = (c2_operand *)0x0;
  last_def = (c2_tuple *)0x0;
  last_sym_def = (c2_tuple *)0x0;
  scale = 1;
  pcVar12 = (c2_symbol *)0x0;
  redispatch = 1;
  iVar11 = 0;
  part_size = 0;
  iVar13 = 0;
  if (addr != (c2_operand *)0x0) {
    part_size = addr->type & 0xfff;
  }
  new_base = index_op;
  if (def_tuple != (c2_tuple *)0x0) {
    do {
      new_base = base_op;
      new_index = index_op;
      switch(def_tuple->op) {
      case 0x15b:
        if (def_tuple == t) goto switchD_1071cb32_caseD_15c;
        switch(def_tuple->src->kind) {
        case '\x01':
        case '\x02':
          if (redispatch == 0) {
            node_free((c2_node *)index_op);
            new_index = def_tuple->src;
            if (new_index->sym->def == (c2_tuple *)0x0) {
              redispatch = 1;
            }
          }
          else {
            if (base_op != (c2_operand *)0x0) {
              node_free((c2_node *)base_op);
            }
            new_base = def_tuple->src;
            if (new_base->sym->def == (c2_tuple *)0x0) {
              redispatch = 0;
            }
          }
          def_tuple->src = (c2_operand *)0x0;
          tuple_unlink_free(def_tuple);
          iVar11 = 1;
          break;
        case '\x03':
          if (def_tuple->src->op == 0x14a) {
            if (iVar13 == 0) {
              if (redispatch == 0) {
                if (scale != 1) goto switchD_1071cc51_caseD_4;
                node_free((c2_node *)index_op);
                index_op = def_tuple->src;
              }
              else {
                if (base_op != (c2_operand *)0x0) {
                  node_free((c2_node *)base_op);
                }
                base_op = def_tuple->src;
              }
              def_tuple->src = (c2_operand *)0x0;
              tuple_unlink_free(def_tuple);
              iVar11 = 1;
              iVar13 = 1;
            }
            goto switchD_1071cc51_caseD_4;
          }
          if (pcVar12 != (c2_symbol *)0x0) goto switchD_1071cb32_caseD_15c;
          if (redispatch == 0) {
            if (scale != 1) goto switchD_1071cc51_caseD_4;
            node_free((c2_node *)index_op);
            new_index = (c2_operand *)0x0;
            pcVar12 = def_tuple->src->sym;
            tuple_unlink_free(def_tuple);
            iVar11 = 1;
            redispatch = redispatch ^ 1;
          }
          else {
            if (base_op != (c2_operand *)0x0) {
              node_free((c2_node *)base_op);
              base_op = (c2_operand *)0x0;
            }
            pcVar12 = def_tuple->src->sym;
            tuple_unlink_free(def_tuple);
            iVar11 = 1;
            redispatch = redispatch ^ 1;
            new_base = base_op;
          }
          break;
        default:
          goto switchD_1071cb32_caseD_15c;
        case '\a':
          if (redispatch == 0) {
            node_free((c2_node *)index_op);
            redispatch = 1;
            disp = disp + (def_tuple->src->u18).lo * scale;
            tuple_unlink_free(def_tuple);
            iVar11 = 1;
            new_index = (c2_operand *)0x0;
          }
          else {
            if (base_op != (c2_operand *)0x0) {
              node_free((c2_node *)base_op);
              base_op = (c2_operand *)0x0;
            }
            redispatch = 0;
            disp = (int)&((def_tuple->src->u18).reg)->fe + disp;
            tuple_unlink_free(def_tuple);
            iVar11 = 1;
            new_base = base_op;
          }
        }
        break;
      default:
switchD_1071cb32_caseD_15c:
        redispatch = redispatch ^ 1;
        break;
      case 0x16d:
        def_src = def_tuple->src;
        bVar4 = def_src->kind;
        switch(bVar4) {
        case 1:
        case 2:
        case 6:
          new_base = def_src->next;
          bVar9 = new_base->kind;
          switch(bVar9) {
          case 1:
          case 2:
          case 6:
            if (redispatch != 0) {
              if (index_op == (c2_operand *)0x0) {
                materialize_memory_sources(def_tuple);
                if (base_op != (c2_operand *)0x0) {
                  node_free((c2_node *)base_op);
                }
                new_base = def_tuple->src;
                def_tuple->src = (c2_operand *)0x0;
                index_op = new_base->next;
                new_base->next = (c2_operand *)0x0;
                if (def_tuple != t) {
                  tuple_unlink_free(def_tuple);
                }
LAB_1071cc8f:
                pcVar8 = new_base->sym->def;
                goto LAB_1071cd25;
              }
              goto code_r0x1071cfae;
            }
            if (base_op == (c2_operand *)0x0) {
              if (scale == 1) {
                materialize_memory_sources(def_tuple);
                base_op = def_tuple->src;
                node_free((c2_node *)index_op);
                index_op = def_tuple->src->next;
                base_op->next = (c2_operand *)0x0;
                goto LAB_1071d257;
              }
              goto switchD_1071cc51_caseD_4;
            }
            break;
          case 3:
            if (redispatch == 0) {
              if (scale == 1) {
                if (new_base->op == 0x14a) {
                  if (base_op != (c2_operand *)0x0) break;
                  if (iVar13 == 0) {
                    materialize_memory_sources(def_tuple);
                    base_op = def_tuple->src->next;
                    node_free((c2_node *)index_op);
                    index_op = def_tuple->src;
                    index_op->next = (c2_operand *)0x0;
LAB_10776565:
                    def_tuple->src = (c2_operand *)0x0;
                    tuple_unlink_free(def_tuple);
                    goto LAB_1071ce28;
                  }
                  goto switchD_1071cc51_caseD_4;
                }
                if (pcVar12 == (c2_symbol *)0x0) {
                  materialize_memory_sources(def_tuple);
                  pcVar12 = def_tuple->src->next->sym;
                  goto LAB_1071d240;
                }
              }
            }
            else if (new_base->op == 0x14a) {
              if ((index_op == (c2_operand *)0x0) && (iVar13 == 0)) {
                materialize_memory_sources(def_tuple);
                if (base_op != (c2_operand *)0x0) {
                  node_free((c2_node *)base_op);
                }
                index_op = def_tuple->src;
                base_op = index_op->next;
                index_op->next = (c2_operand *)0x0;
                goto LAB_1071ce0c;
              }
            }
            else if (pcVar12 == (c2_symbol *)0x0) {
              materialize_memory_sources(def_tuple);
              pcVar12 = def_tuple->src->next->sym;
              if (base_op != (c2_operand *)0x0) {
                node_free((c2_node *)base_op);
              }
              new_base = def_tuple->src;
              node_free((c2_node *)new_base->next);
              new_base->next = (c2_operand *)0x0;
              def_tuple->src = (c2_operand *)0x0;
              if (def_tuple == t) goto LAB_1071cc8f;
              tuple_unlink_free(def_tuple);
              pcVar8 = new_base->sym->def;
              goto LAB_1071cd25;
            }
code_r0x1071cfae:
            if (base_op == (c2_operand *)0x0) goto switchD_1071cc51_caseD_4;
            break;
          default:
            goto switchD_1071cc51_caseD_4;
          case 7:
            if (redispatch != 0) {
              materialize_memory_sources(def_tuple);
              factor = (int)(def_tuple->src->next->u18).reg;
              if (base_op != (c2_operand *)0x0) {
                node_free((c2_node *)base_op);
              }
              new_base = def_tuple->src;
              node_free((c2_node *)new_base->next);
              new_base->next = (c2_operand *)0x0;
LAB_1071cd01:
              disp = (int)&((c2_symbol *)factor)->fe + disp;
              def_tuple->src = (c2_operand *)0x0;
joined_r0x1071ceb0:
              if (def_tuple != t) {
                tuple_unlink_free(def_tuple);
              }
              pcVar8 = new_base->sym->def;
LAB_1071cd25:
              iVar11 = 1;
              new_index = index_op;
              if (pcVar8 != (c2_tuple *)0x0) goto LAB_1071cacb;
              redispatch = 0;
              base_op = new_base;
              goto LAB_1071cad7;
            }
            materialize_memory_sources(def_tuple);
            index_op = def_tuple->src;
            disp = disp + (index_op->next->u18).lo * scale;
            node_free((c2_node *)index_op->next);
            index_op->next = (c2_operand *)0x0;
LAB_1071d257:
            def_tuple->src = (c2_operand *)0x0;
            goto LAB_1071d25e;
          }
LAB_1071cfb6:
          if (index_op != (c2_operand *)0x0) {
            if (((1 << (bVar4 & 0x1f) & 6U) == 0) || (def_tuple->src->sym->def == (c2_tuple *)0x0))
            {
              if (((1 << (bVar9 & 0x1f) & 6U) != 0) && (new_base->sym->def != (c2_tuple *)0x0))
              goto LAB_1071d0da;
            }
            else if (((1 << (bVar9 & 0x1f) & 6U) == 0) || (new_base->sym->def == (c2_tuple *)0x0)) {
LAB_1071d0da:
              if (scale == 1) {
                if (redispatch == 0) {
                  if (((((1 << (base_op->kind & 0x1f) & 6U) != 0) &&
                       (pcVar8 = base_op->sym->def, pcVar8 != (c2_tuple *)0x0)) &&
                      (last_def == pcVar8)) &&
                     (iVar6 = tuple_in_range((c2_node *)last_def,(c2_node *)def_tuple,(c2_node *)t),
                     iVar6 == 0)) {
                    new_base = def_tuple->src;
                    if (((1 << (new_base->kind & 0x1f) & 6U) == 0) ||
                       (new_base->sym->def == (c2_tuple *)0x0)) {
                      new_index = new_base->next;
                      redispatch = 1;
                      base_op->next = new_index->next;
                      new_index->next = (c2_operand *)0x0;
                      new_base->next = base_op;
                      base_op = new_index;
                    }
                    else {
                      base_op->next = new_base->next;
                      def_tuple->src = base_op;
                      new_base->next = (c2_operand *)0x0;
                      redispatch = 1;
                      base_op = new_base;
                    }
                    break;
                  }
                }
                else if ((((1 << (index_op->kind & 0x1f) & 6U) != 0) &&
                         (pcVar8 = index_op->sym->def, pcVar8 != (c2_tuple *)0x0)) &&
                        ((last_sym_def == pcVar8 &&
                         (iVar6 = tuple_in_range((c2_node *)last_sym_def,(c2_node *)def_tuple,
                                                 (c2_node *)t), iVar6 == 0)))) {
                  new_base = def_tuple->src;
                  if (((1 << (new_base->kind & 0x1f) & 6U) == 0) ||
                     (new_base->sym->def == (c2_tuple *)0x0)) {
                    new_index = new_base->next;
                    redispatch = 0;
                    index_op->next = new_index->next;
                    new_index->next = (c2_operand *)0x0;
                    new_base->next = index_op;
                    index_op = new_index;
                  }
                  else {
                    index_op->next = new_base->next;
                    def_tuple->src = index_op;
                    new_base->next = (c2_operand *)0x0;
                    redispatch = 0;
                    index_op = new_base;
                  }
                  goto LAB_1071cad7;
                }
              }
            }
            else if (scale == 1) {
              if (redispatch == 0) {
                uVar5 = 1 << (base_op->kind & 0x1f);
                if ((((uVar5 & 6) == 0) || (base_op->sym->def == (c2_tuple *)0x0)) &&
                   (((uVar5 & 0x380) != 0 ||
                    (((uVar5 & 0x18) != 0 ||
                     (iVar6 = operand_used_between(base_op,def_tuple,t,(c2_symbol *)0x0), iVar6 == 0
                     )))))) {
                  new_base = def_tuple->src->next;
                  def_tuple->src->next = base_op;
                  base_op = index_op;
                  index_op = new_base;
                  goto LAB_1071cad7;
                }
              }
              else {
                uVar5 = 1 << (index_op->kind & 0x1f);
                if ((((uVar5 & 6) == 0) || (index_op->sym->def == (c2_tuple *)0x0)) &&
                   (((uVar5 & 0x380) != 0 ||
                    (((uVar5 & 0x18) != 0 ||
                     (iVar6 = operand_used_between(index_op,def_tuple,t,(c2_symbol *)0x0),
                     iVar6 == 0)))))) {
                  new_base = def_tuple->src;
                  def_tuple->src = index_op;
                  index_op->next = new_base->next;
                  new_base->next = (c2_operand *)0x0;
                  new_index = base_op;
                  goto LAB_1071cacb;
                }
              }
            }
          }
          goto switchD_1071cc51_caseD_4;
        case 3:
          new_base = def_src->next;
          bVar9 = new_base->kind;
          if (((1 << (bVar9 & 0x1f) & 6U) != 0) || (new_base->kind == '\x06')) {
            if (redispatch != 0) {
              if (def_tuple->src->op == 0x14a) {
                if ((index_op != (c2_operand *)0x0) || (iVar13 != 0)) goto LAB_107767c6;
                materialize_memory_sources(def_tuple);
                if (base_op != (c2_operand *)0x0) {
                  node_free((c2_node *)base_op);
                }
                base_op = def_tuple->src;
                index_op = base_op->next;
LAB_1071cf10:
                base_op->next = (c2_operand *)0x0;
LAB_1071ce0c:
                def_tuple->src = (c2_operand *)0x0;
                if (def_tuple != t) {
                  tuple_unlink_free(def_tuple);
                }
                redispatch = 0;
LAB_1071ce28:
                iVar11 = 1;
                iVar13 = 1;
                goto LAB_1071cad7;
              }
              if (pcVar12 != (c2_symbol *)0x0) goto LAB_107767c6;
              materialize_memory_sources(def_tuple);
              pcVar12 = def_tuple->src->sym;
              if (base_op != (c2_operand *)0x0) {
                node_free((c2_node *)base_op);
              }
              new_base = def_tuple->src->next;
              node_free((c2_node *)def_tuple->src);
              def_tuple->src = (c2_operand *)0x0;
              goto joined_r0x1071ceb0;
            }
            if (scale != 1) goto LAB_107767c6;
            if (def_tuple->src->op != 0x14a) {
              if (pcVar12 != (c2_symbol *)0x0) goto LAB_107767c6;
              materialize_memory_sources(def_tuple);
              pcVar12 = def_tuple->src->sym;
              goto LAB_1077660f;
            }
            if (base_op != (c2_operand *)0x0) goto LAB_1071cfb6;
            if (iVar13 == 0) {
              materialize_memory_sources(def_tuple);
              node_free((c2_node *)index_op);
              base_op = def_tuple->src;
              index_op = base_op->next;
              base_op->next = (c2_operand *)0x0;
              goto LAB_10776565;
            }
            goto switchD_1071cc51_caseD_4;
          }
          if (new_base->kind != '\a') goto switchD_1071cc51_caseD_4;
          new_index = def_tuple->src;
          if (new_index->op == 0x14a) {
            if (iVar13 != 0) {
LAB_107767c6:
              fold_address_expression_part
                        (bVar9,def_tuple,index_op,base_op,new_base,redispatch,t,scale,iVar11,pcVar12
                         ,iVar13,last_def,last_sym_def,part_size,(uint)bVar9,bVar4,addr,disp,
                         replace_fn);
              return;
            }
            if (redispatch != 0) {
              disp = (int)&((new_base->u18).reg)->fe + disp;
              if (base_op != (c2_operand *)0x0) {
                node_free((c2_node *)base_op);
              }
              base_op = def_tuple->src;
              node_free((c2_node *)base_op->next);
              goto LAB_1071cf10;
            }
            if (scale != 1) goto LAB_107767c6;
            disp = (int)&((new_base->u18).reg)->fe + disp;
            node_free((c2_node *)index_op);
            index_op = def_tuple->src;
            node_free((c2_node *)index_op->next);
            index_op->next = (c2_operand *)0x0;
            def_tuple->src = (c2_operand *)0x0;
            tuple_unlink_free(def_tuple);
            iVar11 = 1;
            redispatch = 1;
            iVar13 = 1;
          }
          else {
            if (pcVar12 != (c2_symbol *)0x0) goto LAB_107767c6;
            if (redispatch != 0) {
              pcVar12 = new_index->sym;
              disp = (int)&((new_base->u18).reg)->fe + disp;
              if (base_op != (c2_operand *)0x0) {
                node_free((c2_node *)base_op);
                base_op = (c2_operand *)0x0;
              }
              node_free((c2_node *)def_tuple->src->next);
              node_free((c2_node *)def_tuple->src);
              def_tuple->src = (c2_operand *)0x0;
              if (def_tuple != t) {
                tuple_unlink_free(def_tuple);
              }
              iVar11 = 1;
              redispatch = 0;
              goto LAB_1071cad7;
            }
            if (scale != 1) goto LAB_107767c6;
            pcVar12 = new_index->sym;
            disp = (int)&((new_base->u18).reg)->fe + disp;
            node_free((c2_node *)index_op);
            tuple_unlink_free(def_tuple);
            iVar11 = 1;
            redispatch = 1;
            index_op = (c2_operand *)0x0;
          }
          break;
        default:
          goto switchD_1071cb32_caseD_15c;
        case 7:
          bVar4 = def_src->next->kind;
          if (((1 << (bVar4 & 0x1f) & 6U) == 0) && (bVar4 != 6)) {
            redispatch = redispatch ^ 1;
            goto LAB_1071cacb;
          }
          if (redispatch != 0) {
            materialize_memory_sources(def_tuple);
            factor = (def_tuple->src->u18).lo;
            if (base_op != (c2_operand *)0x0) {
              node_free((c2_node *)base_op);
            }
            new_base = def_tuple->src->next;
            node_free((c2_node *)def_tuple->src);
            goto LAB_1071cd01;
          }
          materialize_memory_sources(def_tuple);
          disp = disp + (def_tuple->src->u18).lo * scale;
LAB_1077660f:
          node_free((c2_node *)index_op);
          index_op = def_tuple->src->next;
          def_tuple->src->next = (c2_operand *)0x0;
LAB_1071d25e:
          tuple_unlink_free(def_tuple);
          pcVar8 = index_op->sym->def;
LAB_1071d382:
          iVar11 = 1;
          if (pcVar8 != (c2_tuple *)0x0) goto LAB_1071cad7;
          redispatch = 1;
        }
        goto LAB_1071d394;
      case 0x16e:
        if ((def_tuple->src->next->kind != '\a') ||
           ((bVar4 = def_tuple->src->kind, (1 << (bVar4 & 0x1f) & 6U) == 0 && (bVar4 != 6))))
        goto switchD_1071cc51_caseD_4;
        if (redispatch == 0) {
          materialize_memory_sources(def_tuple);
          disp = disp - (def_tuple->src->next->u18).lo * scale;
LAB_1071d240:
          node_free((c2_node *)index_op);
          index_op = def_tuple->src;
          node_free((c2_node *)index_op->next);
          index_op->next = (c2_operand *)0x0;
          goto LAB_1071d257;
        }
        materialize_memory_sources(def_tuple);
        disp = disp - (def_tuple->src->next->u18).lo;
        if (base_op != (c2_operand *)0x0) {
          node_free((c2_node *)base_op);
        }
        new_base = def_tuple->src;
        node_free((c2_node *)new_base->next);
        new_base->next = (c2_operand *)0x0;
        def_tuple->src = (c2_operand *)0x0;
        if (def_tuple != t) {
          tuple_unlink_free(def_tuple);
        }
        iVar11 = 1;
        if (new_base->sym->def != (c2_tuple *)0x0) break;
        redispatch = 0;
        base_op = new_base;
        goto LAB_1071cad7;
      case 0x16f:
        new_base = def_tuple->src->next;
        if (((new_base->kind == '\a') &&
            ((bVar4 = def_tuple->src->kind, (1 << (bVar4 & 0x1f) & 6U) != 0 || (bVar4 == 6)))) &&
           ((factor = (new_base->u18).lo, factor == 1 ||
            (((factor == 2 || (factor == 4)) || (factor == 8)))))) {
          if (redispatch == 0) {
            if (scale != 1) goto switchD_1071cc51_caseD_4;
            materialize_memory_sources(def_tuple);
            node_free((c2_node *)index_op);
            index_op = def_tuple->src;
            node_free((c2_node *)index_op->next);
            index_op->next = (c2_operand *)0x0;
            def_tuple->src = (c2_operand *)0x0;
            tuple_unlink_free(def_tuple);
            pcVar8 = index_op->sym->def;
            scale = factor;
            goto LAB_1071d382;
          }
          if ((index_op == (c2_operand *)0x0) || (scale == 1)) {
            materialize_memory_sources(def_tuple);
            scale = factor;
            if (base_op != (c2_operand *)0x0) {
              node_free((c2_node *)base_op);
              scale = factor;
            }
            new_index = def_tuple->src;
            node_free((c2_node *)new_index->next);
            new_index->next = (c2_operand *)0x0;
            def_tuple->src = (c2_operand *)0x0;
            if (def_tuple != t) {
              tuple_unlink_free(def_tuple);
            }
            pcVar8 = new_index->sym->def;
LAB_1071d30c:
            iVar11 = 1;
            new_base = index_op;
            if (pcVar8 != (c2_tuple *)0x0) {
              redispatch = 0;
              base_op = index_op;
              index_op = new_index;
              goto LAB_1071cad7;
            }
            break;
          }
        }
        goto switchD_1071cc51_caseD_4;
      case 0x171:
        new_base = def_tuple->src->next;
        if (((new_base->kind == '\a') &&
            ((bVar4 = def_tuple->src->kind, (1 << (bVar4 & 0x1f) & 6U) != 0 || (bVar4 == 6)))) &&
           ((uVar3 = (new_base->u18).lo, uVar3 == 1 || ((uVar3 == 2 || (uVar3 == 3)))))) {
          if (redispatch == 0) {
            if (scale == 1) {
              materialize_memory_sources(def_tuple);
              scale = 1 << ((byte)uVar3 & 0x1f);
              node_free((c2_node *)index_op);
              index_op = def_tuple->src;
              node_free((c2_node *)index_op->next);
              index_op->next = (c2_operand *)0x0;
              def_tuple->src = (c2_operand *)0x0;
              tuple_unlink_free(def_tuple);
              pcVar8 = index_op->sym->def;
              goto LAB_1071d382;
            }
          }
          else if ((index_op == (c2_operand *)0x0) || (scale == 1)) {
            materialize_memory_sources(def_tuple);
            scale = 1 << ((byte)uVar3 & 0x1f);
            if (base_op != (c2_operand *)0x0) {
              node_free((c2_node *)base_op);
            }
            new_index = def_tuple->src;
            node_free((c2_node *)new_index->next);
            new_index->next = (c2_operand *)0x0;
            def_tuple->src = (c2_operand *)0x0;
            if (def_tuple != t) {
              tuple_unlink_free(def_tuple);
            }
            pcVar8 = new_index->sym->def;
            goto LAB_1071d30c;
          }
        }
switchD_1071cc51_caseD_4:
        redispatch = redispatch ^ 1;
        new_base = base_op;
        new_index = index_op;
      }
LAB_1071cacb:
      base_op = new_base;
      index_op = new_index;
      if (redispatch == 0) {
LAB_1071cad7:
        if (((index_op == (c2_operand *)0x0) ||
            (def_tuple = index_op->sym->def, def_tuple == (c2_tuple *)0x0)) ||
           (def_tuple == last_sym_def)) goto LAB_1071cadf;
        uVar2 = def_tuple->type;
        last_sym_def = def_tuple;
      }
      else {
LAB_1071d394:
        new_base = index_op;
        if (base_op == (c2_operand *)0x0) goto LAB_1071caeb;
        def_tuple = base_op->sym->def;
        if ((def_tuple == (c2_tuple *)0x0) || (def_tuple == last_def)) goto LAB_1071cadf;
        uVar2 = def_tuple->type;
        last_def = def_tuple;
      }
      if (((uVar2 & 0xfff) != 4) || (def_tuple == (c2_tuple *)0x0)) goto LAB_1071cadf;
    } while( true );
  }
LAB_1071cb00:
  mem_op = 0x146;
  index_op = new_base;
LAB_1071cb05:
  if (iVar11 == 0) {
    return;
  }
  iVar13 = disp >> 0x1f;
  if (addr != (c2_operand *)0x0) {
    switch(mem_op) {
    case 0x146:
      index_op = addr->base;
      puVar1 = &index_op->flags;
      *puVar1 = *puVar1 & 0xdf;
      tuple_remove_src(t,index_op);
      addr->base = (c2_operand *)0x0;
      addr->disp = disp;
      addr->op = 0x152;
      return;
    default:
      ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\x86\\addr.c",0x402);
    case 0x14a:
      iVar11 = disp_within_symbol(base_op->sym,disp);
      if (iVar11 != 0) {
        uVar10 = addr->type;
        pcVar12 = symbol_get_part(base_op->sym,uVar10,part_size,disp);
        index_op = operand_new_sym(0x14a,uVar10,pcVar12);
        index_op->flags11 = (addr->flags11 ^ index_op->flags11) & 8 ^ index_op->flags11;
        index_op->flags = (addr->flags ^ index_op->flags) & 0x40 ^ index_op->flags;
        (*replace_fn)(t,addr,index_op);
        node_free((c2_node *)base_op);
        return;
      }
      insert_fn = tuple_insert_before;
      index_op = addr->base;
      pcVar7 = operand_new_intconst(0x1004,disp,iVar13);
      break;
    case 0x14b:
      iVar11 = disp_within_symbol(pcVar12,disp);
      if (iVar11 != 0) {
        uVar10 = addr->type;
        pcVar12 = symbol_get_part(pcVar12,uVar10,part_size,disp);
        index_op = operand_new_sym(0x14b,uVar10,pcVar12);
        index_op->flags11 = (addr->flags11 ^ index_op->flags11) & 8 ^ index_op->flags11;
        index_op->flags = (addr->flags ^ index_op->flags) & 0x40 ^ index_op->flags;
        (*replace_fn)(t,addr,index_op);
        return;
      }
      insert_fn = tuple_insert_before;
      index_op = addr->base;
      pcVar7 = operand_new_intconst(0x1004,disp,iVar13);
      base_op = operand_new_symaddr(0x14b,pcVar12);
      break;
    case 0x14c:
      index_op = operand_new_mem(0x14c,addr->type,pcVar12,disp,base_op,(c2_operand *)0x0,addr->tag);
      bVar9 = (addr->flags11 ^ index_op->flags11) & 7 ^ index_op->flags11;
      bVar4 = addr->flags;
      index_op->flags11 = (bVar9 ^ addr->flags11) & 8 ^ bVar9;
      index_op->flags = (bVar4 ^ index_op->flags) & 0x40 ^ index_op->flags;
      (*replace_fn)(t,addr,index_op);
      return;
    case 0x14d:
      if (((scale < 2) && (base_op->kind != '\x01')) && (index_op->kind != '\x01')) {
        new_base = addr->base;
        pcVar8 = tuple_new_binary(0x2d,base_op->type,new_base,base_op,index_op,tuple_insert_before,t
                                 );
        new_base->sym->def = pcVar8;
        addr->disp = disp;
        addr->base_sym = pcVar12;
        return;
      }
      index_op = operand_new_mem(0x14d,addr->type,pcVar12,disp,base_op,index_op,addr->tag);
      if (scale < 8) {
        bVar4 = (byte)(scale >> 1);
      }
      else {
        bVar4 = 3;
      }
      bVar9 = (index_op->flags ^ bVar4) & 0xf ^ index_op->flags;
      bVar4 = (addr->flags11 ^ index_op->flags11) & 7 ^ index_op->flags11;
      index_op->flags11 = (bVar4 ^ addr->flags11) & 8 ^ bVar4;
      index_op->flags = (addr->flags ^ bVar9) & 0x40 ^ bVar9;
      (*replace_fn)(t,addr,index_op);
      return;
    case 0x14e:
      index_op = operand_new_mem(0x14e,addr->type,base_op->sym,disp,(c2_operand *)0x0,index_op,
                                 addr->tag);
      if (scale < 8) {
        bVar4 = (byte)(scale >> 1);
      }
      else {
        bVar4 = 3;
      }
      bVar9 = (bVar4 ^ index_op->flags) & 0xf ^ index_op->flags;
      bVar4 = addr->flags;
      index_op->flags11 = (addr->flags11 ^ index_op->flags11) & 8 ^ index_op->flags11;
      index_op->flags = (bVar4 ^ bVar9) & 0x40 ^ bVar9;
      (*replace_fn)(t,addr,index_op);
      node_free((c2_node *)base_op);
      return;
    case 0x14f:
      index_op = operand_new_mem(0x14f,addr->type,pcVar12,disp,(c2_operand *)0x0,index_op,addr->tag)
      ;
      if (scale < 8) {
        bVar4 = (byte)(scale >> 1);
      }
      else {
        bVar4 = 3;
      }
      bVar4 = (bVar4 ^ index_op->flags) & 0xf ^ index_op->flags;
      bVar9 = (addr->flags11 ^ index_op->flags11) & 7 ^ index_op->flags11;
      index_op->flags11 = (bVar9 ^ addr->flags11) & 8 ^ bVar9;
      index_op->flags = (addr->flags ^ bVar4) & 0x40 ^ bVar4;
      (*replace_fn)(t,addr,index_op);
      return;
    }
    pcVar8 = tuple_new_binary(0x16d,0x1004,index_op,base_op,pcVar7,insert_fn,t);
    index_op->sym->def = pcVar8;
    return;
  }
  switch(mem_op) {
  case 0x146:
    uVar10 = t->type;
    t->op = 1;
    break;
  default:
    ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\x86\\addr.c",0x49b);
  case 0x14a:
    t->op = 0x12;
    if (disp == 0) {
      tuple_append_src(t,base_op);
      return;
    }
    iVar11 = disp_within_symbol(base_op->sym,disp);
    if (iVar11 != 0) {
      pcVar12 = symbol_get_part(base_op->sym,base_op->sym->type,4,disp);
      index_op = operand_new_symaddr(0x14a,pcVar12);
      tuple_append_src(t,index_op);
      node_free((c2_node *)base_op);
      return;
    }
    t->op = 0x16d;
    tuple_append_src(t,base_op);
    uVar10 = 0x1004;
    break;
  case 0x14b:
    t->op = 1;
    iVar13 = disp_within_symbol(pcVar12,disp);
    if (iVar13 == 0) {
      index_op = operand_new_addr(0x150,t->type,pcVar12,disp,(c2_operand *)0x0,(c2_operand *)0x0);
      tuple_append_src(t,index_op);
      return;
    }
    goto joined_r0x10776bc5;
  case 0x14c:
    if ((pcVar12 == (c2_symbol *)0x0) && (disp == 0)) {
      t->op = 1;
      tuple_append_src(t,base_op);
      return;
    }
    index_op = t->dst;
    factor = (int)pcVar12;
    if ((((((1 << (index_op->kind & 0x1f) & 6U) == 0) || (index_op->sym->def == (c2_tuple *)0x0)) ||
         ((base_op->kind == '\x01' && (base_op->sym->def == (c2_tuple *)0x0)))) &&
        ((base_op->kind != '\x01' || (base_op->sym != index_op->sym)))) ||
       ((pcVar12 != (c2_symbol *)0x0 && (iVar13 = disp_within_symbol(pcVar12,disp), iVar13 == 0))))
    {
      t->op = 0x12;
      index_op = operand_new_addr(0x14c,t->type,(c2_symbol *)factor,disp,base_op,(c2_operand *)0x0);
      tuple_append_src(t,index_op);
      return;
    }
    tuple_append_src(t,base_op);
    if (pcVar12 == (c2_symbol *)0x0) {
      if (disp < 1) {
        t->op = 0x32;
        disp = -disp;
      }
      else {
        t->op = 0x2d;
      }
      pcVar7 = operand_new_intconst(t->type,disp,disp >> 0x1f);
      tuple_append_src(t,pcVar7);
      return;
    }
    t->op = 0x2d;
joined_r0x10776bc5:
    if (disp != 0) {
      pcVar12 = symbol_get_part(pcVar12,pcVar12->type,4,disp);
    }
    index_op = operand_new_symaddr(0x14b,pcVar12);
    tuple_append_src(t,index_op);
    return;
  case 0x14d:
    if (((((scale < 2) && (disp == 0)) && (pcVar12 == (c2_symbol *)0x0)) &&
        (((new_base = t->dst, (1 << (new_base->kind & 0x1f) & 6U) != 0 &&
          (factor = (int)new_base->sym, ((c2_symbol *)factor)->def != (c2_tuple *)0x0)) ||
         ((base_op->kind == '\x01' &&
          (factor = (int)new_base->sym, (c2_symbol *)factor == base_op->sym)))))) &&
       (((base_op->kind != '\x01' || (((base_op->u18).reg)->cls != '\x02')) ||
        ((index_op->kind != '\x01' ||
         ((((index_op->u18).reg)->cls != '\x02' || (base_op->sym == (c2_symbol *)factor)))))))) {
      t->op = 0x2d;
      tuple_append_src(t,base_op);
      tuple_append_src(t,index_op);
      if ((1 << (index_op->kind & 0x1f) & 6U) == 0) {
        return;
      }
      pcVar8 = index_op->sym->def;
      if (pcVar8 == (c2_tuple *)0x0) {
        return;
      }
      if (pcVar8->op != 1) {
        return;
      }
      tuple_replace_src(t,index_op,pcVar8->src);
      tuple_unlink_free(pcVar8);
      return;
    }
    t->op = 0x12;
    index_op = operand_new_addr(0x14d,t->type,pcVar12,disp,base_op,index_op);
    if (scale < 8) {
      index_op->flags = ((byte)(scale >> 1) ^ index_op->flags) & 0xf ^ index_op->flags;
      tuple_append_src(t,index_op);
      return;
    }
LAB_1071dad8:
    index_op->flags = (index_op->flags ^ 3) & 0xf ^ index_op->flags;
    tuple_append_src(t,index_op);
    return;
  case 0x14e:
    pcVar12 = base_op->sym;
    t->op = 0x12;
    index_op = operand_new_addr(0x14e,t->type,pcVar12,disp,(c2_operand *)0x0,index_op);
    if (scale < 8) {
      bVar4 = (byte)(scale >> 1);
    }
    else {
      bVar4 = 3;
    }
    index_op->flags = (bVar4 ^ index_op->flags) & 0xf ^ index_op->flags;
    tuple_append_src(t,index_op);
    node_free((c2_node *)base_op);
    return;
  case 0x14f:
    if (((pcVar12 != (c2_symbol *)0x0) || (disp != 0)) ||
       ((((base_op = t->dst, (1 << (base_op->kind & 0x1f) & 6U) == 0 ||
          (base_op->sym->def == (c2_tuple *)0x0)) ||
         ((index_op->kind == '\x01' && (index_op->sym->def == (c2_tuple *)0x0)))) &&
        ((index_op->kind != '\x01' || (index_op->sym != base_op->sym)))))) {
      t->op = 0x12;
      index_op = operand_new_addr(0x14f,t->type,pcVar12,disp,(c2_operand *)0x0,index_op);
      if (scale < 8) {
        index_op->flags = ((byte)(scale >> 1) ^ index_op->flags) & 0xf ^ index_op->flags;
        tuple_append_src(t,index_op);
        return;
      }
      goto LAB_1071dad8;
    }
    t->op = 0x2a;
    tuple_append_src(t,index_op);
    if (scale < 8) {
      uVar10 = t->type;
      disp = scale >> 1;
      iVar13 = scale >> 0x1f;
    }
    else {
      uVar10 = t->type;
      iVar13 = 0;
      disp = 3;
    }
  }
  pcVar7 = operand_new_intconst(uVar10,disp,iVar13);
  tuple_append_src(t,pcVar7);
  return;
LAB_1071cadf:
  new_base = index_op;
  if (base_op == (c2_operand *)0x0) {
LAB_1071caeb:
    index_op = new_base;
    if (new_base == (c2_operand *)0x0) {
      mem_op = 0x14b;
      if (pcVar12 == (c2_symbol *)0x0) goto LAB_1071cb00;
    }
    else {
      new_base->flags = new_base->flags & 0xef;
      new_base->next = (c2_operand *)0x0;
      if (scale < 2) {
        mem_op = 0x14c;
        index_op = (c2_operand *)0x0;
        base_op = new_base;
      }
      else {
        mem_op = 0x14f;
      }
    }
  }
  else {
    base_op->next = (c2_operand *)0x0;
    base_op->flags = base_op->flags & 0xef;
    if (base_op->kind == '\x03') {
      if (index_op == (c2_operand *)0x0) {
        mem_op = 0x14a;
      }
      else {
        index_op->next = (c2_operand *)0x0;
        index_op->flags = index_op->flags & 0xef;
        mem_op = 0x14e;
      }
    }
    else if (index_op == (c2_operand *)0x0) {
      mem_op = 0x14c;
    }
    else {
      index_op->next = (c2_operand *)0x0;
      index_op->flags = index_op->flags & 0xef;
      mem_op = 0x14d;
    }
  }
  goto LAB_1071cb05;
}

