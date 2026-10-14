int __cdecl opt_D_handler(char **argv,int *index)

{
  uchar *p;
  uchar *p_2;
  size_t name_len;
  char *name;
  optrec *user;
  optrec *user_2;
  optrec *pass_rec;
  uchar *def;
  int i;
  
  i = *index;
  def = (uchar *)(argv[i] + 2);
  *index = i + 1;
  if (*def == '\0') {
    def = (uchar *)argv[i + 1];
    *index = i + 2;
  }
  if ((def != (uchar *)0x0) && (*def != '\0')) {
    p = _mbschr(def,0x23);
    if (p != (uchar *)0x0) {
      *p = '=';
    }
    p_2 = _mbschr(def,0x3d);
    if (p_2 == (uchar *)0x0) {
      name_len = strlen((char *)def);
    }
    else {
      name_len = (int)p_2 - (int)def;
    }
    name = xmalloc(name_len + 1);
    strncpy(name,(char *)def,name_len);
    name[name_len] = '\0';
    user = optrec_new("D",name,(char *)0x0,'\0');
    drv_bU_undefine(user);
    optrec_free(user);
    xfree(name);
    user_2 = optrec_new("D",(char *)def,(char *)0x0,'\0');
    list_append(&g_driver_ctx_ptr->user_options,user_2);
    pass_rec = optrec_new("D",(char *)def,"1PM",'\x04');
    list_append(&g_driver_ctx_ptr->pass_options,pass_rec);
    (pass_rec->src).owner = user_2;
    user_2->refcount = '\x01';
    return 0;
  }
  cl_error(0x7d4,"D");
}

