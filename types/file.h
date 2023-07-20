/**
 * struct file -- ...
 * @fmode:	The file mode identifies the file as either readable or writable (or both), by means of the bits FMODE_READ and FMODE_WRITE.
 *		You might want to check this field for read/write permission in your open or ioctl function, but you don’t need to check permissions for read and write, because the kernel checks before invoking your method.
 *		An attempt to read or write when the file has not been opened for that type of access is rejected without the driver even knowing about it.
 * @f_op:	The operations associated with the file.
 *		The kernel assigns the pointer as part of its implementation of `open` and then reads it when it needs to ?(dispatch) any operations.
 *		The value in `filp->f_op` is never saved by the kernel for later reference; this means that you can change the file operations associated with your file, and the new methods will be effective after you return to the caller.
 *		For example, the code for `open` associated with major number 1 (/dev/null, /dev/zero, and so on) substitutes the operations in `filp->f_op` depending on the minor number being opened.
 *		This practice allows the implementation of several behaviors under the same major number without introducing overhead at each system call.
 *		The ability to replace the file operations is the kernel equivalent of "method overriding" in object-oriented programming.
 */
struct file {
	union {
		struct llist_node	f_llist;
		struct rcu_head 	f_rcuhead;
		unsigned int 		f_iocb_flags;
	};
	struct path			f_path;
	struct inode *			f_inode;	// cached value
	const struct file_operations *	f_op;

	/*
	 * Protects f_ep, f_flags.
	 * Must not be taken from IRQ context.
	 */
	spinlock_t		f_lock;
	atomic_long_t		f_count;
	unsigned int 		f_flags;
	fmode_t			f_mode;
	struct mutex		f_pos_lock;
	loff_t			f_pos;
	struct fown_struct	f_owner;
	const struct cred	*f_cred;
	struct file_ra_state	f_ra;

	u64			f_version;
#ifdef CONFIG_SECURITY
	void			*f_security;
#endif
	/* needed for tty driver, and maybe others */
	void			*private_data;

#ifdef CONFIG_EPOLL
	/* Used by fs/eventpoll.c to link all the hooks to this file */
	struct hlist_head	*f_ep;
#endif /* #ifdef CONFIG_EPOLL */
	struct address_space	*f_mapping;
	errseq_t		f_wb_err;
	errseq_t		f_sb_err; /* for syncfs */
} __randomize_layout
  __attribute__((aligned(4)));	/* lest something weird decides that 2 is OK */
