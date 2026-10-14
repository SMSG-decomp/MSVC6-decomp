void * __fastcall merge_sort_operand_list(void *head,void *cmp)

{
  c2_node *pcVar1;
  c2_node *pcVar2;
  int iVar3;
  c2_node *pcVar4;
  c2_node *a;
  c2_node *pcVar5;
  int local_c;
  c2_node *local_8;
  c2_cmp_fn *local_4;
  
  a = (c2_node *)0x0;
  pcVar5 = (c2_node *)0x0;
  local_c = 1;
  local_8 = head;
  local_4 = cmp;
  if (head != (void *)0x0) {
    do {
      if (pcVar5 == head) {
        return head;
      }
      pcVar4 = (c2_node *)&local_8;
      if (head != (c2_node *)0x0) {
        while( true ) {
          a = head;
          pcVar5 = a->next;
          pcVar1 = a;
          for (iVar3 = 1; (pcVar5 != (c2_node *)0x0 && (iVar3 < local_c)); iVar3 = iVar3 + 1) {
            pcVar1 = pcVar1->next;
            pcVar5 = pcVar1->next;
          }
          pcVar5 = pcVar1->next;
          if (pcVar5 == (c2_node *)0x0) break;
          pcVar1->next = (c2_node *)0x0;
          pcVar1 = pcVar5->next;
          pcVar2 = pcVar5;
          for (iVar3 = 1; (pcVar1 != (c2_node *)0x0 && (iVar3 < local_c)); iVar3 = iVar3 + 1) {
            pcVar2 = pcVar2->next;
            pcVar1 = pcVar2->next;
          }
          pcVar1 = pcVar2->next;
          pcVar2->next = (c2_node *)0x0;
          pcVar2 = merge_operand_lists(a,pcVar5,local_4);
          pcVar4->next = pcVar2;
          head = local_8;
          if (pcVar1 == (c2_node *)0x0) goto LAB_1070ae8a;
          iVar3 = local_c * 2;
          head = pcVar1;
          if (0 < iVar3) {
            do {
              pcVar4 = pcVar4->next;
              iVar3 = iVar3 + -1;
            } while (iVar3 != 0);
          }
        }
        pcVar4->next = a;
        pcVar5 = (c2_node *)0x0;
        head = local_8;
      }
LAB_1070ae8a:
      local_c = local_c * 2;
    } while (a != head);
  }
  return head;
}

