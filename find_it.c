
#include "lem_in.h"

void     decide_path1(t_lst **tmp, char **st, t_lst **addr, t_lst **path)
{
    char **cut;

    cut = ft_strsplit((*tmp)->data, '-');
    create_path(path, cut[0]);
    if (duplicate2(*path, cut[0]))
        delete_node(path, ft_lstlen(*path));
    *st = cut[0];
    *addr = addr_pos(*tmp, loc(*tmp, *st));
}

void     decide_path2(t_lst **tmp, char **st, t_lst **addr, t_lst **path)
{
    char **cut;

    cut = ft_strsplit((*tmp)->data, '-');
    create_path(path, cut[1]);
    if (duplicate2(*path, cut[0]))
        delete_node(path, ft_lstlen(*path));
    *st = cut[1];
    *addr = addr_pos(*tmp, loc(*tmp, *st));
}

t_lst    *top_bot(char *st, char *en, t_lst **path, t_lst *res)
{
    t_lst   *tmp;
    t_lst   *addr;
    char    **cut;
    char    *en1;

    tmp = res;
    en1 = ft_strdup(st); 
    while (tmp)
    {
        if (ft_strcmp(st,ft_strreturn(tmp->data, st)) == 0)
        {
            cut = ft_strsplit(tmp->data, '-');
            if (!ft_strcmp(cut[1], ft_strreturn(tmp->data, st)))
            {
                cut = ft_strsplit(tmp->data, '-');
                does_link(res, st, en) == 1 ? create_path(path, en) : decide_path1(&tmp, &st, &addr, path);
                /* if (does_link(res, st, en))
                    create_path(path, en);
                else
                    decide_path1(&tmp, &st, &addr, path); */
                    /* create_path(path, cut[0]);
                    if (duplicate2(*path, cut[0]))
                        delete_node(path, ft_lstlen(*path));}
                st = cut[0];
                addr = addr_pos(tmp, loc(tmp, st)); */
            }
            else
            {
                does_link(res, st, en) == 1 ? create_path(path, en) : decide_path2(&tmp, &st, &addr, path);
                /* if (does_link(res, st, en))
                    create_path(path, en);
                else
                    decide_path2(&tmp, &st, &addr, path); */
                    /* create_path(path, cut[1]);
                    if (duplicate2(*path, cut[0]))
                        delete_node(path, ft_lstlen(*path));}
                st = cut[1];
                addr = addr_pos(tmp, loc(tmp, st)); */}
            
            if (!ft_strcmp(pos(*path, ft_lstlen(*path)), en))
                break;
        }
        tmp = tmp->right;
        if (tmp == NULL && ft_strcmp(pos(*path, ft_lstlen(*path)), en))//the new start should match one of the next link rooms
        {
            if ((loc(res, en1) - 1) != ft_lstlen(res) && (loc(res, en1) - 1) != 1 && !(*path)->right)
                break;
            if (addr->right == NULL)
                break;
            tmp = addr->right;
            delete_node(path, loc(*path, pos(*path, ft_lstlen(*path)))-1);
            st = pos(*path, ft_lstlen(*path));
        }
    }
    return (tmp);
}