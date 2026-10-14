void * __fastcall reader_count_live_eh_objects(void *marker,c2_tuple *call,void *fn)

{
  c2_operand *pcVar1;
  c2_tuple *pcVar2;
  c2_operand *pcVar3;
  int iVar4;
  
  iVar4 = **(int **)((int)marker + 0x20);
  for (pcVar1 = call->src->next; pcVar1 != (c2_operand *)0x0; pcVar1 = pcVar1->next) {
    if (((((((pcVar1->flags & 0x20) == 0) && (pcVar2 = pcVar1->sym->def, pcVar2->op == 0x16a)) &&
          (pcVar3 = pcVar2->src, (1 << (pcVar3->kind & 0x1f) & 6U) != 0)) &&
         ((pcVar2 = pcVar3->sym->def, pcVar2 != (c2_tuple *)0x0 && (pcVar2->kind == '\x12')))) &&
        (((pcVar2->u20).intrinsic.id == 0xdf &&
         (pcVar2 = pcVar2->src->sym->def->prev, pcVar2->op == 0x1a0)))) &&
       (((((pcVar2->u20).cond_cells)->kind & 0x10) != 0 ||
        ((g_opt_eh_enabled != 0 &&
         ((((*(uint *)(*(int *)fn + 0x14) & 0x800) != 0 &&
           ((*(uint *)((int)fn + 0x34) & 0x10000) == 0)) ||
          ((g_cur_function != (c2_function *)0x0 &&
           (((g_cur_function->fsym->attrs & 0x800) != 0 && ((g_cur_function->flags & 0x10000) == 0))
           )))))))))) {
      iVar4 = iVar4 + -1;
    }
  }
  if (iVar4 != 0) {
    **(int **)((int)marker + 0x20) = iVar4;
    return marker;
  }
  node_free(marker);
  return (void *)0x0;
}

