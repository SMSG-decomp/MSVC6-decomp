char * __cdecl mre_options_string(driver_ctx *ctx)

{
  optrec *opt_00;
  char *s;
  char letter;
  char *buf;
  uchar *path;
  char **items;
  char letter_2;
  char *text;
  char *p;
  char *p_2;
  size_t n;
  char *text_2;
  char *p_3;
  char *p_4;
  optrec *opt;
  char **item_2;
  char **item;
  size_t n_2;
  int size;
  char **item_next;
  size_t count;
  char **item_3;
  
  buf = xmalloc(0x400);
  path = xmalloc(0x400);
  count = 0;
  for (opt = ctx->pass_options; opt != (optrec *)0x0; opt = opt->next) {
    letter = option_pass_letter_in(opt,"Mm");
    if (letter != '\0') {
      count = count + 1;
    }
  }
  items = xmalloc(count << 2);
  opt_00 = ctx->pass_options;
  size = 0;
  item_3 = items;
  for (; opt_00 != (optrec *)0x0; opt_00 = opt_00->next) {
    letter_2 = option_pass_letter_in(opt_00,"Mm");
    item_next = item_3;
    if (letter_2 != '\0') {
      g_scratch[0] = '-';
      text = strcpy_end(g_scratch + 1,opt_00->name);
      s = opt_00->value;
      if (s != (char *)0x0) {
        if (letter_2 == 'm') {
          p = path_full((char *)path,s,0x400);
          if (p == (char *)0x0) {
            strcpy((char *)path,opt_00->value);
          }
          _mbslwr(path);
          quote_argument(buf,(char *)path);
        }
        else {
          quote_argument(buf,s);
        }
        strcpy_end(text,buf);
      }
      p_2 = xstrdup(g_scratch);
      item_next = item_3 + 1;
      *item_3 = p_2;
      n = strlen(g_scratch);
      size = size + 1 + n;
    }
    item_3 = item_next;
  }
  qsort(items,count,4,mre_option_compare);
  text_2 = xmalloc(size + 1);
  p_4 = text_2;
  item_2 = items;
  n_2 = count;
  if (0 < (int)count) {
    do {
      p_3 = strcpy_end(p_4,*item_2);
      *p_3 = ' ';
      p_4 = p_3 + 1;
      item_2 = item_2 + 1;
      n_2 = n_2 - 1;
    } while (n_2 != 0);
  }
  p_4[-1] = '\0';
  item = items;
  if (0 < (int)count) {
    do {
      xfree(*item);
      item = item + 1;
      count = count - 1;
    } while (count != 0);
  }
  xfree(items);
  xfree(path);
  xfree(buf);
  return text_2;
}

