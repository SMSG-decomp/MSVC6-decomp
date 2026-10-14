c2_inline_binding * __fastcall
inline_bind_actual_arguments(c2_function *callee,c2_tuple *entry,c2_tuple *call)

{
  uint8_t *puVar1;
  byte bVar2;
  uint16_t type;
  c2_symbol *pcVar3;
  c2_inline_binding *pcVar4;
  c2_inline_binding *binding;
  int iVar5;
  c2_operand *pcVar6;
  c2_symbol *pcVar7;
  c2_tuple *pcVar8;
  c2_operand *src;
  ushort uVar9;
  c2_operand *actual_opnd;
  c2_tuple *pcVar10;
  c2_inline_binding *new_head;
  c2_inline_binding *head;
  c2_tuple *copy;
  c2_tuple *arg_tuple;
  c2_insert_fn *insert_fn;
  c2_fe_symbol *sret;
  c2_operand *formal_opnd;
  
  sret = callee->struct_return;
  if (sret == (c2_fe_symbol *)0x0) {
    head = (c2_inline_binding *)0x0;
    actual_opnd = call->src->next;
  }
  else {
    head = arena_alloc(4,0x10);
    actual_opnd = call->src->next;
    pcVar8 = actual_opnd->sym->def;
    *(c2_tuple **)&((c2_symbol *)head)->cls = pcVar8;
    pcVar7 = (c2_symbol *)node_clone((c2_node *)pcVar8->src);
    ((c2_symbol *)head)->part_next = pcVar7;
    pcVar7->part_next = (c2_symbol *)0x0;
    pcVar7 = sret->storage_sym;
    actual_opnd = actual_opnd->next;
    ((c2_symbol *)head)->storage = pcVar7;
    pcVar7->order_next = (c2_symbol *)head;
    (pcVar7->storage->u18).inline_callee = callee;
  }
  formal_opnd = entry->src;
  pcVar4 = head;
  do {
    if ((((actual_opnd == (c2_operand *)0x0) || ((1 << (actual_opnd->kind & 0x1f) & 6U) == 0)) ||
        (pcVar8 = actual_opnd->sym->def, pcVar8 == (c2_tuple *)0x0)) ||
       ((pcVar8->op != 0x15a && (pcVar8->op != 0x16a)))) {
      return pcVar4;
    }
    arg_tuple = pcVar8;
    binding = arena_alloc(4,0x10);
    pcVar7 = formal_opnd->sym;
    binding->arg = pcVar8;
    binding->formal = pcVar7;
    pcVar3 = pcVar7->storage;
    pcVar3->order_next = (c2_symbol *)binding;
    (pcVar3->u18).inline_callee = callee;
    for (; pcVar3 != (c2_symbol *)0x0; pcVar3 = pcVar3->part_next) {
      if (pcVar3 == pcVar7) {
LAB_10751333:
        uVar9 = pcVar3->type & 0xf000;
        if (uVar9 != 0x4000) {
          if ((pcVar7->type & 0xf000) == 0x4000) goto LAB_107513d3;
          if (uVar9 != 0x4000) goto LAB_10751364;
        }
        if ((pcVar7->type & 0xf000) != 0x4000) goto LAB_107513d3;
      }
      else if ((pcVar3->offset < pcVar7->size + pcVar7->offset) &&
              (pcVar7->offset < pcVar3->size + pcVar3->offset)) goto LAB_10751333;
LAB_10751364:
    }
    if ((pcVar7->flags5 & 2) == 0) {
      pcVar6 = pcVar8->src;
      binding->value = pcVar6;
      bVar2 = pcVar6->kind;
      if (((1 << (bVar2 & 0x1f) & 6U) == 0) ||
         (pcVar10 = pcVar6->sym->def, pcVar10 == (c2_tuple *)0x0)) {
        if (bVar2 == 2) {
          if ((pcVar6->flags & 0x40) == 0) {
            iVar5 = inline_range_may_write(pcVar6,&pcVar8->next,call);
            goto joined_r0x10751508;
          }
        }
        else {
          if (bVar2 != 6) goto LAB_107513bd;
          if ((((callee->flags & 1) == 0) && ((pcVar6->flags & 0x40) == 0)) &&
             (iVar5 = inline_range_may_write(pcVar6,&arg_tuple->next,call), iVar5 == 0)) {
            pcVar6 = binding->value->base;
            if (((1 << (pcVar6->kind & 0x1f) & 6U) == 0) ||
               (pcVar8 = pcVar6->sym->def, pcVar8 == (c2_tuple *)0x0)) {
              if (pcVar6->kind != 2) goto LAB_107513bd;
              if ((pcVar6->flags & 0x40) != 0) goto LAB_10751470;
              iVar5 = inline_range_may_write(pcVar6,&binding->arg->next,call);
            }
            else {
              iVar5 = inline_tree_reads_written(pcVar8,call);
            }
            goto joined_r0x10751508;
          }
        }
LAB_10751470:
        binding->value = (c2_operand *)0x0;
      }
      else {
        if ((pcVar10->op == 400) && (pcVar8 = call, (pcVar10->u20).intrinsic.id == 0xde)) {
          do {
            pcVar8 = find_next_use_of_dst(pcVar8,(c2_operand **)&copy);
          } while (pcVar8->kind != '\x0e');
          pcVar6 = pcVar8->dst;
          if (pcVar6 != (c2_operand *)0x0) {
            if (((1 << (pcVar6->kind & 0x1f) & 6U) != 0) && (pcVar6->sym->def != (c2_tuple *)0x0)) {
              type = pcVar8->type;
              insert_fn = tuple_insert_after;
              pcVar10 = pcVar8;
              src = operand_new_temp_sym(type);
              copy = tuple_new(0x15b,type,pcVar6,src,insert_fn,pcVar10);
              pcVar7 = pcVar6->sym;
              if (pcVar7->storage->part_next == (c2_symbol *)0x0) {
                pcVar7->def = copy;
              }
              else {
                symbol_mark_overlapping_parts(pcVar7,copy);
              }
              pcVar6 = tuple_replace_dst(pcVar8,pcVar6,copy->src);
            }
            puVar1 = &pcVar6->sym->flags7;
            *puVar1 = *puVar1 | 2;
          }
        }
        if ((callee->flags & 1) != 0) goto LAB_10751470;
        iVar5 = inline_tree_reads_written(binding->value->sym->def,call);
joined_r0x10751508:
        if (iVar5 != 0) goto LAB_10751470;
      }
LAB_107513bd:
      if (binding->value != (c2_operand *)0x0) {
        pcVar6 = (c2_operand *)node_clone((c2_node *)binding->value);
        binding->value = pcVar6;
        pcVar6->rank = 0;
      }
    }
LAB_107513d3:
    new_head = binding;
    if (head != (c2_inline_binding *)0x0) {
      head->next = binding;
      new_head = pcVar4;
    }
    actual_opnd = actual_opnd->next;
    formal_opnd = formal_opnd->next;
    head = binding;
    pcVar4 = new_head;
  } while( true );
}

