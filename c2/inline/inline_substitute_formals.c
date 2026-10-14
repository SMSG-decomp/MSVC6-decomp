void __fastcall inline_substitute_formals(c2_tuple *first)

{
  uint8_t uVar1;
  ushort type;
  c2_operand *value;
  c2_operand *pcVar2;
  c2_symbol *pcVar3;
  c2_operand *pcVar4;
  c2_operand *pcVar5;
  uint32_t uVar6;
  c2_tuple *pcVar7;
  c2_replace_fn *replace_fn;
  c2_tuple *resume;
  c2_operand *found_list;
  c2_operand *next_sub;
  c2_inline_binding *binding;
  c2_operand *bound;
  
  do {
    resume = (c2_tuple *)0x0;
    do {
      if ((first->flags & 1) != 0) {
        uVar6 = first->op;
        if (uVar6 == 0x191) {
          resume = first->next;
          first = (first->u20).default_label;
        }
        else if (uVar6 == 0x1a0) {
          pcVar7 = ((first->u20).eh_construct)->object->funclet->cfg->first->head;
          inline_substitute_formals(pcVar7);
          tuple_range_clear_line(pcVar7,(c2_tuple *)0x0);
        }
        else if (uVar6 == 0x1ab) {
          inline_substitute_formals((first->u20).default_label);
        }
        pcVar2 = first->src;
joined_r0x10751dc4:
        pcVar4 = pcVar2;
        if (pcVar4 != (c2_operand *)0x0) {
          next_sub = pcVar4->next;
          pcVar2 = next_sub;
          if (((pcVar4->kind == '\x02') && (pcVar4->sym->cls == '\x05')) &&
             (pcVar3 = pcVar4->sym->storage, (pcVar3->u18).expr != (c2_cse_expr *)0x0)) {
            binding = (c2_inline_binding *)pcVar3->order_next;
            value = binding->value;
            if (value != (c2_operand *)0x0) {
              if ((pcVar4->flags & 0x20) != 0) {
                if ((1 << (value->kind & 0x1f) & 0x18U) != 0) {
                  pcVar2 = find_mem_operand_using(first,pcVar4,&found_list);
                  pcVar3 = binding->value->sym;
                  uVar1 = pcVar3->cls;
                  if (((uVar1 == '\x03') || (uVar1 == '\x04')) ||
                     ((uVar1 == '\x05' || (uVar6 = 0x14b, uVar1 == '\x06')))) {
                    uVar6 = 0x14a;
                  }
                  replace_fn = tuple_replace_dst;
                  if (found_list != first->dst) {
                    replace_fn = tuple_replace_src;
                  }
                  pcVar3 = symbol_get_part(pcVar3,pcVar2->type,pcVar2->type & 0xfff,0);
                  pcVar4 = operand_new_sym(uVar6,pcVar2->type,pcVar3);
                  (*replace_fn)(first,pcVar2,pcVar4);
                  pcVar2 = next_sub;
                  goto joined_r0x10751dc4;
                }
                if (value->kind == '\a') {
                  pcVar5 = find_mem_operand_using(first,pcVar4,&found_list);
                  pcVar4->flags = pcVar4->flags & 0xdf;
                  tuple_remove_src(first,pcVar4);
                  pcVar2 = binding->value;
                  pcVar5->base = (c2_operand *)0x0;
                  pcVar5->op = 0x152;
                  pcVar5->disp = (int)&((pcVar2->u18).reg)->fe + pcVar5->disp;
                  pcVar2 = next_sub;
                  goto joined_r0x10751dc4;
                }
              }
              type = pcVar4->type;
              if (value->type == type) goto LAB_10751e3f;
              switch(value->kind) {
              case '\x01':
              case '\x02':
                pcVar3 = symbol_get_part(value->sym,type,type & 0xfff,pcVar4->sym->offset);
                if (binding->value->kind == '\x02') {
                  value = operand_new_sym(binding->value->op,pcVar4->type,pcVar3);
                }
                else {
                  value = operand_new_reg(0x149,pcVar4->type,pcVar3,pcVar3->storage);
                }
                break;
              case '\x03':
              case '\x04':
                pcVar2 = tuple_replace_src(first,pcVar4,value);
                pcVar2->type = type;
                goto LAB_10751e49;
              default:
                ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\inline.c",0x678);
              case '\x06':
                value->type = type;
                break;
              case '\a':
                value = operand_new_intconst(type,(value->u18).lo,value->tag);
                break;
              case '\t':
                value = operand_new_fconst(type,(c2_float_const *)value->sym);
              }
LAB_10751e3f:
              tuple_replace_src(first,pcVar4,value);
LAB_10751e49:
              bound = binding->value;
              if ((((1 << (bound->kind & 0x1f) & 6U) != 0) &&
                  (pcVar7 = bound->sym->def, pcVar7 != (c2_tuple *)0x0)) ||
                 ((pcVar2 = next_sub, bound->kind == 6 &&
                  (((1 << (bound->base->kind & 0x1f) & 6U) != 0 &&
                   (pcVar7 = bound->base->sym->def, pcVar7 != (c2_tuple *)0x0)))))) {
                tuple_unlink(pcVar7);
                tuple_insert_before(first,pcVar7);
                hoist_defining_tuples(pcVar7,'\0');
                pcVar2 = next_sub;
              }
            }
          }
          goto joined_r0x10751dc4;
        }
      }
      first = first->next;
    } while (first != (c2_tuple *)0x0);
    first = resume;
    if (resume == (c2_tuple *)0x0) {
      return;
    }
  } while( true );
}

