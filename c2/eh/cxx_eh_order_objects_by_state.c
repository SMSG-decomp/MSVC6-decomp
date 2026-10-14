c2_eh_object_cell * __fastcall cxx_eh_order_objects_by_state(c2_eh_object_cell *list,int n)

{
  c2_eh_state *pcVar1;
  c2_eh_object_cell **ppcVar2;
  c2_eh_state *pcVar3;
  c2_eh_object_cell *pcVar4;
  c2_eh_object_cell *pcVar5;
  c2_eh_object_cell *pcVar6;
  c2_eh_object_cell *pcVar7;
  c2_eh_state *pcVar8;
  c2_eh_object_cell *local_4;
  
  pcVar1 = g_eh_current_state;
  pcVar6 = list;
  local_4 = (c2_eh_object_cell *)n;
  if (list != (c2_eh_object_cell *)0x0) {
    do {
      if (pcVar1 != (c2_eh_state *)0x0) {
        pcVar3 = pcVar1;
        do {
          pcVar8 = pcVar3->origin;
          if (pcVar3->origin == (c2_eh_state *)0x0) {
            pcVar8 = pcVar3;
          }
          if (pcVar6->object == pcVar8) {
            if (pcVar3 != (c2_eh_state *)0x0) goto LAB_10754ecd;
            break;
          }
          pcVar3 = pcVar3->parent;
        } while (pcVar3 != (c2_eh_state *)0x0);
      }
      pcVar5 = pcVar6->prev;
      if (pcVar5 == (c2_eh_object_cell *)0x0) {
        list = pcVar6->next;
      }
      else {
        pcVar5->next = pcVar6->next;
      }
      if (pcVar6->next != (c2_eh_object_cell *)0x0) {
        pcVar6->next->prev = pcVar5;
      }
      local_4 = (c2_eh_object_cell *)((int)&local_4[-1].object + 3);
LAB_10754ecd:
      ppcVar2 = &pcVar6->next;
      pcVar6 = *ppcVar2;
    } while (*ppcVar2 != (c2_eh_object_cell *)0x0);
    if (list != (c2_eh_object_cell *)0x0) {
      pcVar6 = (c2_eh_object_cell *)0x0;
      pcVar5 = local_4;
      do {
        pcVar4 = pcVar5;
        pcVar7 = pcVar6;
        if (pcVar1 == (c2_eh_state *)0x0) {
LAB_10754f29:
          pcVar4->next = (c2_eh_object_cell *)0x0;
          pcVar7->prev = (c2_eh_object_cell *)0x0;
          return pcVar7;
        }
        if (list != (c2_eh_object_cell *)0x0) {
          pcVar4 = list;
          do {
            pcVar3 = pcVar1->origin;
            if (pcVar1->origin == (c2_eh_state *)0x0) {
              pcVar3 = pcVar1;
            }
            if (pcVar4->object == pcVar3) {
              if (pcVar4 != (c2_eh_object_cell *)0x0) {
                pcVar7 = pcVar4->prev;
                if (pcVar7 == (c2_eh_object_cell *)0x0) {
                  list = pcVar4->next;
                }
                else {
                  pcVar7->next = pcVar4->next;
                }
                if (pcVar4->next != (c2_eh_object_cell *)0x0) {
                  pcVar4->next->prev = pcVar7;
                }
                pcVar7 = pcVar4;
                if (pcVar6 != (c2_eh_object_cell *)0x0) {
                  pcVar5->next = pcVar4;
                  pcVar4->prev = pcVar5;
                  pcVar7 = pcVar6;
                }
                local_4 = (c2_eh_object_cell *)((int)&local_4[-1].object + 3);
                pcVar5 = pcVar4;
                pcVar6 = pcVar7;
                if (local_4 == (c2_eh_object_cell *)0x0) goto LAB_10754f29;
              }
              break;
            }
            pcVar4 = pcVar4->next;
          } while (pcVar4 != (c2_eh_object_cell *)0x0);
        }
        pcVar1 = pcVar1->parent;
      } while( true );
    }
  }
  return (c2_eh_object_cell *)0x0;
}

