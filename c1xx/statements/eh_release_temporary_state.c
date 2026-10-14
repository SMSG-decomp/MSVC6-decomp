int __cdecl eh_release_temporary_state(int temp)

{
  c1_flow_state **ppcVar1;
  int iVar2;
  c1_flow_state *rec;
  
  if (g_flow_state_abandoned != '\0') {
    return -1;
  }
  if (g_sizeof_depth != 0) {
    return -1;
  }
  rec = g_flow_state_top;
  if (g_flow_state_top == (c1_flow_state *)0x0) {
    return -1;
  }
  do {
    if (rec->kind == 0xd) {
      if ((rec->flags & 1) == 0) {
        if ((rec->flags & 2) == 0) {
          iVar2 = flow_record_names_temporary(rec->subject,temp);
          if (iVar2 != 0) {
            func_flow_state_release(rec);
LAB_1041fbe1:
            return rec->word1c;
          }
        }
        else {
          iVar2 = sizeof_is_active();
          if (iVar2 != 0) goto LAB_1041fbe1;
        }
      }
    }
    else if (rec->kind != 0x3e) {
      return -1;
    }
    ppcVar1 = &rec->prev;
    rec = *ppcVar1;
    if (*ppcVar1 == (c1_flow_state *)0x0) {
      return -1;
    }
  } while( true );
}

