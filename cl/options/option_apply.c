int __cdecl option_apply(char **argv,int *index,int user)

{
  cl_optrec *pcVar1;
  optrec *r;
  optrec *r_2;
  int rc;
  int rc_2;
  optrec *matched;
  optrec *old_2;
  int rc_3;
  int rc_4;
  optrec *r_3;
  optrec *matched_2;
  optrec *old;
  optrec *victim;
  optrec *old_3;
  optrec *r_4;
  optrec *matched_4;
  optrec *poVar2;
  optrec *matched_5;
  optrec *r_00;
  int *index_p;
  cl_optrec *pr_2;
  cl_optrec *pr;
  cl_optrec *cur_2;
  cl_optrec *cur_3;
  cl_optrec *cur;
  optrec *removed;
  optrec *rec;
  optdesc *desc;
  cl_u8 *refcount;
  cl_optrec **next_p;
  char **words;
  int *index_p_2;
  cl_optrec **next_p_2;
  cl_u8 *refcount_2;
  cl_u8 *refcount_3;
  cl_optrec *pr_3;
  
  index_p_2 = index;
  words = argv;
  desc = option_lookup(argv,*index);
  if (desc == (optdesc *)0x0) {
    r = optrec_new(words[*index_p_2],(char *)0x0,(char *)0x0,'\0');
    list_append(&g_unknown_options,r);
    *index_p_2 = *index_p_2 + 1;
LAB_00401d22:
    rc = 0;
  }
  else {
    r_2 = option_match_and_take_argument(desc,words,index_p_2);
    if (r_2 != (optrec *)0x0) {
      rec = r_2;
      if ((r_2->flags & 2) != 0) {
        list_append(&g_unknown_options,r_2);
        goto LAB_00401d22;
      }
      (r_2->src).desc = desc;
      if (desc->actions == (char *)0x0) {
        index = (int *)0x0;
      }
      else {
        index = (int *)action_parse_list(desc->actions,r_2);
        if (((optrec *)index != (optrec *)0x0) && (rc_2 = strcmp(r_2->name,"I"), rc_2 != 0)) {
          argv = (char **)0x0;
          matched = optrec_list_extract_matching
                              (&g_driver_ctx_ptr->pass_options,(optrec *)index,(optrec **)&argv);
          pr_2 = matched;
          pr_3 = (cl_optrec *)index;
          if (matched != (optrec *)0x0) {
            do {
              refcount = &((pr_2->src).owner)->refcount;
              *refcount = *refcount + 0xff;
              if (((pr_2->src).owner)->refcount == '\0') {
                old_2 = list_unlink(&g_driver_ctx_ptr->user_options,(pr_2->src).owner);
                optrec_free(old_2);
              }
              next_p = &pr_2->next;
              pr_2 = *next_p;
            } while (pr_2 != (cl_optrec *)0x0);
            optrec_list_free(matched);
            optrec_list_free((optrec *)argv);
            pr_3 = (cl_optrec *)index;
          }
joined_r0x00401dc9:
          poVar2 = pr_3;
          if (poVar2 != (optrec *)0x0) {
            pr_3 = poVar2->next;
            for (pr = g_driver_ctx_ptr->pass_options; r_2 = rec, pr != (cl_optrec *)0x0;
                pr = pr->next) {
              rc_3 = optrec_matches(poVar2,pr);
              if ((rc_3 != 0) && (rc_4 = strcmp(poVar2->passes,pr->passes), rc_4 == 0)) {
                r_3 = list_unlink((optrec **)&index,poVar2);
                optrec_free(r_3);
                r_2 = rec;
                break;
              }
            }
            goto joined_r0x00401dc9;
          }
        }
      }
      if (desc->overridden != (char *)0x0) {
        matched_2 = action_parse_list(desc->overridden,r_2);
        argv = (char **)0x0;
        old = optrec_list_extract_matching
                        (&g_driver_ctx_ptr->pass_options,matched_2,(optrec **)&argv);
        cur_2 = old;
        if (old != (optrec *)0x0) {
          do {
            if ((cur_2->flags & 0x11) == 0) {
              if (g_noover == 0) {
                option_conflict_message(0xfb9,(cur_2->src).owner,r_2);
              }
              victim = list_unlink(&g_driver_ctx_ptr->user_options,(cur_2->src).owner);
              optrec_free(victim);
              pcVar1 = g_driver_ctx_ptr->pass_options;
              while (poVar2 = pcVar1, pcVar1 = cur_2, poVar2 != (optrec *)0x0) {
                pcVar1 = poVar2->next;
                if ((poVar2->src).desc == (cur_2->src).desc) {
                  old_3 = list_unlink(&g_driver_ctx_ptr->pass_options,poVar2);
                  optrec_free(old_3);
                }
              }
              do {
                cur_2 = pcVar1;
                pcVar1 = cur_2->next;
                if (pcVar1 == (cl_optrec *)0x0) break;
              } while ((pcVar1->src).desc == (cur_2->src).desc);
            }
            else {
              refcount_2 = &((cur_2->src).owner)->refcount;
              *refcount_2 = *refcount_2 + 0xff;
              if (((cur_2->src).owner)->refcount == '\0') {
                poVar2 = list_unlink(&g_driver_ctx_ptr->user_options,(cur_2->src).owner);
                optrec_free(poVar2);
              }
            }
            cur_2 = cur_2->next;
          } while (cur_2 != (optrec *)0x0);
          optrec_list_free(old);
        }
        optrec_list_free(matched_2);
        for (cur_3 = (cl_optrec *)argv; cur_3 != (cl_optrec *)0x0; cur_3 = cur_3->next) {
          if (((cur_3->src).desc != (optdesc *)0x0) &&
             (((cur_3->src).desc)->overridden != (char *)0x0)) {
            removed = (optrec *)0x0;
            r_4 = action_parse_list(((cur_3->src).desc)->overridden,cur_3);
            matched_4 = optrec_list_extract_matching((optrec **)&index,r_4,&removed);
            optrec_list_free(matched_4);
            optrec_list_free(r_4);
            optrec_list_free(removed);
          }
        }
        optrec_list_free((optrec *)argv);
      }
      if (desc->incompatible != (char *)0x0) {
        poVar2 = action_parse_list(desc->incompatible,r_2);
        matched_5 = optrec_list_extract_matching
                              (&g_driver_ctx_ptr->pass_options,poVar2,(optrec **)0x0);
        cur = matched_5;
        if (matched_5 != (optrec *)0x0) {
          do {
            if ((cur->flags & 0x11) == 0) {
              option_conflict_message(0x7e0,(cur->src).owner,rec);
            }
            refcount_3 = &((cur->src).owner)->refcount;
            *refcount_3 = *refcount_3 + 0xff;
            if (((cur->src).owner)->refcount == '\0') {
              r_00 = list_unlink(&g_driver_ctx_ptr->user_options,(cur->src).owner);
              optrec_free(r_00);
            }
            next_p_2 = &cur->next;
            cur = *next_p_2;
          } while (cur != (cl_optrec *)0x0);
          optrec_list_free(matched_5);
        }
        optrec_list_free(poVar2);
        r_2 = rec;
      }
      if ((user != 0) && (index_p = index, index != (int *)0x0)) {
        do {
          index_p[5] = (int)r_2;
          r_2->refcount = r_2->refcount + '\x01';
          index_p = (int *)index_p[1];
        } while (index_p != (int *)0x0);
        list_append(&g_driver_ctx_ptr->user_options,r_2);
        list_append(&g_driver_ctx_ptr->pass_options,(optrec *)index);
      }
    }
    rc = 1;
  }
  return rc;
}

