optrec * __cdecl optrec_list_extract_matching(optrec **list,optrec *pattern,optrec **removed)

{
  int match;
  optrec *seen;
  optrec *rec;
  optrec *rec_2;
  optrec *extracted;
  cl_optrec *next;
  optrec *rec_3;
  
  extracted = (optrec *)0x0;
joined_r0x00402124:
  if (pattern == (optrec *)0x0) {
    return extracted;
  }
  next = *list;
joined_r0x00402133:
  do {
    rec_3 = next;
    if (rec_3 == (optrec *)0x0) break;
    next = rec_3->next;
    match = optrec_matches(rec_3,pattern);
    if (match != 0) {
      if ((removed == (optrec **)0x0) ||
         ((((pattern->flags & 1) == 0 || ((rec_3->flags & 0x11) != 0)) &&
          (((pattern->flags & 0x10) == 0 || ((rec_3->flags & 0x10) != 0)))))) {
        rec_2 = list_unlink(list,rec_3);
        list_append(&extracted,rec_2);
        goto joined_r0x00402133;
      }
      seen = *removed;
      if (seen != (optrec *)0x0) {
        do {
          if ((seen->src).desc == (rec_3->src).desc) break;
          seen = seen->next;
        } while (seen != (optrec *)0x0);
        if (seen != (optrec *)0x0) goto joined_r0x00402133;
      }
      rec = optrec_clone((rec_3->src).owner);
      list_append(removed,rec);
    }
  } while( true );
  pattern = pattern->next;
  goto joined_r0x00402124;
}

